/*
Author : cédric liaudet
URL    : https://github.com/SuperNeon/gmwwise

=================================================================================
This library is free software; you can redistribute it and/or modify 
it under the terms of the GNU Lesser General Public License as published
by the Free Software Foundation; either version 2.1 of the License, or (at your option) any later version. 
This library is distributed in the hope that it will be useful, but without any warranty; 
without even the implied warranty of merchantability or fitness for a particular purpose. 
See the GNU Lesser General Public License for more details.
=================================================================================
*/
#include "GMSWwisePCH.h"
#include "GMSWEngine.h"
#include "GMSWBank.h"
#include "wwise/AkDefaultIOHookBlocking.h"

namespace AK
{
    void * __cdecl AllocHook( size_t in_size )
    {
        return malloc( in_size );
    }
    void __cdecl FreeHook( void * in_ptr )
    {
        free( in_ptr );
    }
    void * __cdecl VirtualAllocHook(
        void * in_pMemAddress,
        size_t in_size,
        DWORD in_dwAllocationType,
        DWORD in_dwProtect
        )
    {
        return VirtualAlloc( in_pMemAddress, in_size, in_dwAllocationType, in_dwProtect );
    }

    void __cdecl VirtualFreeHook( 
        void * in_pMemAddress,
        size_t in_size,
        DWORD in_dwFreeType
        )
    {
        VirtualFree( in_pMemAddress, in_size, in_dwFreeType );
    }
}

CAkDefaultIOHookBlocking g_lowLevelIO;

#ifndef AK_OPTIMIZED
    AkMemPoolId g_poolComm = AK_INVALID_POOL_ID;    
#   define COMM_POOL_SIZE          (256 * 1024)
#   define COMM_POOL_BLOCK_SIZE    (48)
#endif

extern "C"
{ 
	//----------------------------------------------------------------
    // Initialization of Wwise. --------------------------------------
	double GMSWInit()
    {
		AkMemSettings memSettings;
		memSettings.uMaxNumPools = 20;

		AKRESULT result = AK::MemoryMgr::Init(&memSettings);
        if(result != AK_Success)
		{
			GMSW_EXCEPTION("unable to initialize the memory manager of wwise.");

            return ErrorCode::Failed;
		}

        AkStreamMgrSettings stmSettings;
        AK::StreamMgr::GetDefaultSettings(stmSettings);
        if(!AK::StreamMgr::Create( stmSettings ) )
        {
            GMSW_EXCEPTION("Could not create the Streaming Manager");

            return ErrorCode::Failed;
        }
        
        AkDeviceSettings deviceSettings;
        AK::StreamMgr::GetDefaultDeviceSettings( deviceSettings );
        if(g_lowLevelIO.Init(deviceSettings) != AK_Success)
		{
			GMSW_EXCEPTION("Could not create the streaming device and Low-Level I/O system.");

            return ErrorCode::Failed;
		}

        AkInitSettings initSettings;
        AkPlatformInitSettings platformInitSettings;
        AK::SoundEngine::GetDefaultInitSettings( initSettings );
        AK::SoundEngine::GetDefaultPlatformInitSettings( platformInitSettings );
        if(AK::SoundEngine::Init(&initSettings, &platformInitSettings) != AK_Success)
        {
            GMSW_EXCEPTION("Could not initialize the Sound Engine.");

            return ErrorCode::Failed;
        }

        AkMusicSettings musicInit;
        AK::MusicEngine::GetDefaultInitSettings( musicInit );
        if(AK::MusicEngine::Init(&musicInit) != AK_Success)
        {
            GMSW_EXCEPTION("Could not initialize the Music Engine.");

            return ErrorCode::Failed;
        }

#ifdef  GMSW_PROFILING
        // Initialize communication.
        AkCommSettings settingsComm;
        AK::Comm::GetDefaultInitSettings( settingsComm );
        if ( AK::Comm::Init( settingsComm ) != AK_Success )
        {
            GMSW_EXCEPTION( "Cannot initialize communication with wwise" );
            return ErrorCode::Failed;
        }
#endif

        return ErrorCode::Success;
    }

	// Shutdown Wwise and free all resources.
    double GMSWShutdown(void)
    {
#ifdef GMSW_PROFILING
        AK::Comm::Term();	   
#endif // AK_OPTIMIZED	

        AK::SoundEngine::UnregisterAllGameObj();

        AK::SoundEngine::StopAll();

		GMSWClearBanks();		

		AK::MusicEngine::Term();

		AK::SoundEngine::Term();
		
		if(AK::IAkStreamMgr::Get())
		{   
			AK::IAkStreamMgr::Get()->Destroy();
		}

		AK::MemoryMgr::Term();

		return ErrorCode::Success;
    }
	
    // Process all events in the sound engine's queue.
    double GMSWRenderAudio()
    {
        AK::SoundEngine::RenderAudio();

		return ErrorCode::Success;
    }

    // Register a plug-in with the sound engine and set the callback functions to create the 
    // plug-in and its parameter node.
    GMSW_API double GMSWRegisterPlugin(double _dType)
    {
        int nType = (int)_dType;
        if(nType < 0)
        {
            GMSW_EXCEPTION("Bad type ID (%d): ID must be higher or equal to 0", nType);
            return ErrorCode::InvalidParameter;
        }

        AKRESULT nResult = AK_Success;
        switch(nType)
        {
            // Sine
        case 0:
            nResult = AK::SoundEngine::RegisterPlugin(AkPluginTypeSource, AKCOMPANYID_AUDIOKINETIC, AKSOURCEID_SINE, CreateSineSource, CreateSineSourceParams);
            break;

            // Tone Generator
        case 1:
            nResult = AK::SoundEngine::RegisterPlugin(AkPluginTypeSource, AKCOMPANYID_AUDIOKINETIC, AKSOURCEID_TONE, CreateToneSource, CreateToneSourceParams);
            break;

            // Silence
        case 2:
            nResult = AK::SoundEngine::RegisterPlugin(AkPluginTypeSource, AKCOMPANYID_AUDIOKINETIC, AKSOURCEID_SILENCE, CreateSilenceSource, CreateSilenceSourceParams);
            break;
            
            // Audio Input
        case 3:
            nResult = AK::SoundEngine::RegisterPlugin(AkPluginTypeSource, AKCOMPANYID_AUDIOKINETIC, AKSOURCEID_AUDIOINPUT, CreateAudioInputSource, CreateAudioInputSourceParams);			
            break;

//             // MP3 Input
//         case 4:
//             AK::SoundEngine::RegisterPlugin(AkPluginTypeSource, AKCOMPANYID_AUDIOKINETIC, AKSOURCEID_MP3, CreateMP3Source, CreateMP3SourceParams);
//             break;        

            // Delay
        case 4:
            nResult = AK::SoundEngine::RegisterPlugin(AkPluginTypeEffect, AKCOMPANYID_AUDIOKINETIC, AKEFFECTID_DELAY, CreateDelayFX, CreateDelayFXParams);
            break;

            // Parametric EQ
        case 5:
            nResult = AK::SoundEngine::RegisterPlugin(AkPluginTypeEffect, AKCOMPANYID_AUDIOKINETIC, AKEFFECTID_PARAMETRICEQ, CreateParametricEQFX, CreateParametricEQFXParams);
            break;

            // Matrix Reverb
        case 6:
            nResult = AK::SoundEngine::RegisterPlugin(AkPluginTypeEffect, AKCOMPANYID_AUDIOKINETIC, AKEFFECTID_MATRIXREVERB, CreateMatrixReverbFX, CreateMatrixReverbFXParams);
            break;

            // Compressor
        case 7:
            AK::SoundEngine::RegisterPlugin(AkPluginTypeEffect, AKCOMPANYID_AUDIOKINETIC, AKEFFECTID_COMPRESSOR, CreateCompressorFX, CreateCompressorFXParams);
            break;

            // Expander
        case 8:
            nResult = AK::SoundEngine::RegisterPlugin(AkPluginTypeEffect, AKCOMPANYID_AUDIOKINETIC, AKEFFECTID_EXPANDER, CreateExpanderFX, CreateExpanderFXParams);
            break;

            // Peak Limiter
        case 9:
            nResult = AK::SoundEngine::RegisterPlugin(AkPluginTypeEffect, AKCOMPANYID_AUDIOKINETIC, AKEFFECTID_PEAKLIMITER, CreatePeakLimiterFX, CreatePeakLimiterFXParams);
            break;

            // Roomverb.
        case 10:
            nResult = AK::SoundEngine::RegisterPlugin(AkPluginTypeEffect, AKCOMPANYID_AUDIOKINETIC, AKEFFECTID_ROOMVERB, CreateRoomVerbFX, CreateRoomVerbFXParams);
            break;

			// Pitch Shifter.
		case 11:
			nResult = AK::SoundEngine::RegisterPlugin(AkPluginTypeEffect, AKCOMPANYID_AUDIOKINETIC, AKEFFECTID_PITCHSHIFTER, CreatePitchShifterFX, CreatePitchShifterFXParams);
			break;

			// Meter
		case 12:
			nResult = AK::SoundEngine::RegisterPlugin(AkPluginTypeEffect, AKCOMPANYID_AUDIOKINETIC, AKEFFECTID_METER, CreateMeterFX, CreateMeterFXParams);
			break;

        default:
            GMSW_EXCEPTION("Unimplemented");
        }

        if(nResult != AK_Success)
        {
            GMSW_EXCEPTION("Unable to register plugin.");
        }

        return ErrorCode::Success;
    }

    // Register a codec type with the sound engine and set the callback functions to create the 
    // codec's file source and bank source nodes.
    GMSW_API double GMSWRegisterCodec(double _type)
    {
        if(_type != 0)
        {
            GMSW_EXCEPTION("Bad type ID : ID must be higher or equal to 0 and lower or equal to 0 (currently, only vorbis codec is supported)");

            return ErrorCode::InvalidParameter;
        }

        AKRESULT nResult;
        switch((int)_type)
        {
        // Vorbis codec.
        case 0:
            nResult = AK::SoundEngine::RegisterCodec(AKCOMPANYID_AUDIOKINETIC, AKCODECID_VORBIS, CreateVorbisFilePlugin, CreateVorbisBankPlugin);
            break;

        default:
            GMSW_EXCEPTION("Unimplemented");
        }

        if(nResult != AK_Success)
        {
            GMSW_EXCEPTION("Unable to register codec.");
        }

        return ErrorCode::Success;
    }
}
