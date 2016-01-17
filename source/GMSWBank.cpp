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
#include "GMSWBank.h"
#include "wwise/AkDefaultIOHookBlocking.h"

#include <list>

extern CAkDefaultIOHookBlocking g_lowLevelIO;

extern "C"
{
    // Array of loaded bank.
	static std::list<AkBankID> s_banksLoaded;
	
	// Unload every lodaded banks.
	void GMSWClearBanks()
	{
		if(!s_banksLoaded.empty())
		{
			auto it = s_banksLoaded.begin(), it_end = s_banksLoaded.end();
			while(it != it_end)
			{
				AK::SoundEngine::UnloadBank((*it), nullptr);
                ++it;
			}

            s_banksLoaded.clear();
		}
	}

    // Set the root folder of the banks.
	double GMSWSetBasePath(const char* _basePath)
	{
        if(!_basePath)
		{
            GMSW_EXCEPTION("Unable to set base path.");

			return ErrorCode::IO;
		}
        
        AkOSChar* wBasePath = (AkOSChar*)AK::MemoryMgr::Malloc(AK_DEFAULT_POOL_ID, (1 + strlen(_basePath)) * sizeof(AkOSChar));
        AKPLATFORM::AkCharToWideChar(_basePath, (AkUInt32)(1 + strlen(_basePath)), wBasePath);
        g_lowLevelIO.SetBasePath(wBasePath);
        AK::MemoryMgr::Free(AK_DEFAULT_POOL_ID, wBasePath);

		return ErrorCode::Success;
	}

	// Load bank by name synchronously.
	double GMSWLoadBank(const char* _bankName)
	{
        AkBankID bankID;
        AKRESULT result = AK::SoundEngine::LoadBank(_bankName, AK_DEFAULT_POOL_ID, bankID);
        if(result != AK_Success)
		{
            char* error;
            switch(result)
            {
            case AK_InsufficientMemory:
                error = "insufficient memory to store bank data.";
                break;
            case AK_BankReadError:
                error = "bank read error.";
                break;
            case AK_WrongBankVersion:
                error = "invalid bank version : make sure the version version of Wwise\n that you used to generate the SoundBanks matches that of the SDK you are currently using.";
                break;
            case AK_InvalidFile:
                error = "file specified could not be opened.";
                break;
            case AK_InvalidParameter:
                error = "invalid parameter, invalid memory alignment.";
                break;
            case AK_Fail:
                error = "load failed for unknow reason.";
                break;
            default:
                error = "unknow error.";
            }

            GMSW_EXCEPTION("Unable to load the bank : %s\nerror: %s", _bankName, error);
			return ErrorCode::Bank;
		}
        
		s_banksLoaded.push_back(bankID);
		return static_cast<double>(bankID);
	}

	// Unload bank by id synchronously. 
	double GMSWUnloadBank(double _bankId)
	{
		if(_bankId < 0)
		{
			GMSW_EXCEPTION("Invalid bank ID : ID must be higher or equal to 0");
			return ErrorCode::InvalidParameter;
		}

		if(AK::SoundEngine::UnloadBank(static_cast<AkBankID>(_bankId), nullptr) != AK_Success)
		{
			GMSW_EXCEPTION("Unable to unload the bank %d", static_cast<AkBankID>(_bankId));
			return ErrorCode::Bank;
		}

        // remove the id from the list.
        s_banksLoaded.remove(static_cast<AkBankID>(_bankId));

		return ErrorCode::Success;
	}
}
