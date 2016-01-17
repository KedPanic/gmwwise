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

//
// Load the GMSWwise DLL.
// Have to be called when you start the program.
//
dll_name = "GMSWwise.dll";

// unable profiling if debug mode activated
if(debug_mode == true)
{
    dll_name = "GMSWwise_p.dll";
}


if(file_exists(dll_name) == false)
{
    show_message("[GMSW] File not found: " + dll_name + ' in directory : ' + working_directory);
}


//=================================================================================
// Base Sound Engine functions.
//=================================================================================
global.dll_GMSWInit=external_define(dll_name, "GMSWInit", dll_cdecl, ty_real, 0);

global.dll_GMSWShutdown=external_define(dll_name, "GMSWShutdown", dll_cdecl, ty_real, 0);

global.dll_GMSWRenderAudio=external_define(dll_name, "GMSWRenderAudio", dll_cdecl, ty_real, 0);

global.dll_GMSWRegisterPlugin=external_define(dll_name, "GMSWRegisterPlugin", dll_cdecl, ty_real, 1, ty_real);

global.dll_GMSWRegisterCodec=external_define(dll_name, "GMSWRegisterCodec", dll_cdecl, ty_real, 1, ty_real);

//=================================================================================
// Banks Management
//=================================================================================
global.dll_GMSWSetBasePath=external_define(dll_name, "GMSWSetBasePath", dll_cdecl, ty_real, 1, ty_string);

global.dll_GMSWLoadBank=external_define(dll_name, "GMSWLoadBank", dll_cdecl, ty_real, 1, ty_string);

global.dll_GMSWUnloadBank=external_define(dll_name, "GMSWUnloadBank", dll_cdecl, ty_real, 1, ty_real);

//=================================================================================
// Event Management
//=================================================================================
global.dll_GMSWPostEvent=external_define(dll_name, "GMSWPostEvent", dll_cdecl, ty_real, 2, ty_real, ty_real);

global.dll_GMSWPostTrigger=external_define(dll_name, "GMSWPostTrigger", dll_cdecl, ty_real, 2, ty_real, ty_real);

global.dll_GMSWStopAllByGameObject=external_define(dll_name, "GMSWStopAllByGameObject", dll_cdecl, ty_real, 1, ty_real);

global.dll_GMSWStopAll=external_define(dll_name, "GMSWStopAll", dll_cdecl, ty_real, 0);

//=================================================================================
// Game object
//=================================================================================
global.dll_GMSWRegisterGameObj=external_define(dll_name, "GMSWRegisterGameObj", dll_cdecl, ty_real, 1, ty_real);

global.dll_GMWUnregisterGameObj=external_define(dll_name, "GMSWUnregisterGameObj", dll_cdecl, ty_real, 1, ty_real);

global.dll_GMSWUnregisterAllGameObj=external_define(dll_name, "GMSWUnregisterAllGameObj", dll_cdecl, ty_real, 0);

global.dll_GMSWSetPosition=external_define(dll_name, "GMSWSetPosition", dll_cdecl, ty_real, 7, ty_real, ty_real, ty_real, ty_real, ty_real, ty_real, ty_real);

global.dll_GMSWSetAttenuationScalingFactor=external_define(dll_name, "GMSWSetAttenuationScalingFactor", dll_cdecl, ty_real, 2, ty_real, ty_real);

//=================================================================================
// Game Sync
//=================================================================================
global.dll_GMSWSetRTPCValue=external_define(dll_name, "GMSWSetRTPCValue", dll_cdecl, ty_real, 6, ty_real, ty_real, ty_real, ty_real, ty_real, ty_real);

global.dll_GMSWSetRTPCValueByPlayingID=external_define(dll_name, "GMSWSetRTPCValueByPlayingID", dll_cdecl, ty_real, 6, ty_real, ty_real, ty_real, ty_real, ty_real, ty_real);

global.dll_GMSWGetRTPCValue=external_define(dll_name, "GMSWGetRTPCValue", dll_cdecl, ty_real, 2, ty_real, ty_real);

global.dll_GMSWResetRTPCValue=external_define(dll_name, "GMSWResetRTPCValue", dll_cdecl, ty_real, 5, ty_real, ty_real, ty_real, ty_real, ty_real);

global.dll_GMSWSetSwitch=external_define(dll_name, "GMSWSetSwitch", dll_cdecl, ty_real, 3, ty_real, ty_real, ty_real);

global.dll_GMSWSetState=external_define(dll_name, "GMSWSetState", dll_cdecl, ty_real, 3, ty_real, ty_real, ty_real);

//=================================================================================
// Listener
//=================================================================================
global.dll_GMSWSetListenerPosition=external_define(dll_name, "GMSWSetListenerPosition", dll_cdecl, ty_real, 7, ty_real, ty_real, ty_real, ty_real, ty_real, ty_real, ty_real);

global.dll_GMSWSetActiveListeners=external_define(dll_name, "GMSWSetActiveListeners", dll_cdecl, ty_real, 2, ty_real, ty_real);

global.dll_GMSWSetListenerScalingFactor=external_define(dll_name, "GMSWSetListenerScalingFactor", dll_cdecl, ty_real, 2, ty_real, ty_real);


// Initialize Wwise
external_call(global.dll_GMSWInit);
