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
#include "GMSWGameSyncs.h"

extern "C"
{    
    // Set the value of a real-time parameter control (by ID).
    GMSW_API double GMSWSetRTPCValue(double _rtpcID, double _rtpcValue, double _gameObjectID, double _valueChangeDuration, double _fadeCurve, double _bypassInternalValueInterpolation)
    {
        AkCurveInterpolation fadeCurve = static_cast<AkCurveInterpolation>((int)_fadeCurve);

        AK::SoundEngine::SetRTPCValue(static_cast<AkRtpcID>(_rtpcID),
            static_cast<AkRtpcValue>(_rtpcValue),
            static_cast<AkGameObjectID>(_gameObjectID),
            static_cast<AkTimeMs>(_valueChangeDuration),
            fadeCurve,
            _bypassInternalValueInterpolation != 0.0);

        return ErrorCode::Success;
    }

    // Set the value of a real-time parameter control (by ID).
    GMSW_API double  GMSWSetRTPCValueByPlayingID(double _rtpcID, double _rtpcValue, double _playingID, double _valueChangeDuration, double _fadeCurve, double _bypassInternalValueInterpolation)
    {
        AkCurveInterpolation fadeCurve = static_cast<AkCurveInterpolation>((int)_fadeCurve);

        AK::SoundEngine::SetRTPCValueByPlayingID(static_cast<AkRtpcID>(_rtpcID),
            static_cast<AkRtpcValue>(_rtpcValue),
            static_cast<AkPlayingID>(_playingID),
            static_cast<AkTimeMs>(_valueChangeDuration),
            fadeCurve,
            _bypassInternalValueInterpolation != 0.0);

        return ErrorCode::Success;
    }

    // Get the value of a real-time parameter control (by ID).
    GMSW_API double  GMSWGetRTPCValue(double _rtpcID, double _gameObjectID)
    {
        AkRtpcValue value;
        AK::SoundEngine::Query::RTPCValue_type type = AK::SoundEngine::Query::RTPCValue_GameObject;
        AKRESULT result = GetRTPCValue(static_cast<AkRtpcID>(_rtpcID), static_cast<AkGameObjectID>(_gameObjectID), value, type);
        if (result == AK_IDNotFound)
        {
            GMSW_EXCEPTION("The game object was not registered or the rtpc name could not be found");
            return ErrorCode::InvalidParameter;
        }

        if (result == AK_Fail)
        {
            GMSW_EXCEPTION("The RTPC value could not be obtained");
            return ErrorCode::Failed;
        }

        return value;
    }

    // Reset the value of the game parameter to its default value, as specified in the Wwise project.
    GMSW_API double  GMSWResetRTPCValue(double _rtpcID, double _gameObjectID, double _valueChangeDuration, double _fadeCurve, double _bypassInternalValueInterpolation)
    {
        AkCurveInterpolation fadeCurve = static_cast<AkCurveInterpolation>((int)_fadeCurve);
        AK::SoundEngine::ResetRTPCValue(static_cast<AkRtpcID>(_rtpcID),
            static_cast<AkGameObjectID>(_gameObjectID),
            static_cast<AkTimeMs>(_valueChangeDuration),
            fadeCurve,
            _bypassInternalValueInterpolation != 0.0);

        return ErrorCode::Success;
    }

    // Set the state of a switch group (by IDs).
    GMSW_API double GMSWSetSwitch(double _switchGroup, double _switch, double _gameObjectID)
    {
        AkSwitchGroupID switchGroup = static_cast<AkSwitchGroupID>(_switchGroup);
        if (switchGroup == AK_INVALID_UNIQUE_ID)
        {
            GMSW_EXCEPTION("Invalid switch group ID : ID must be higher than 0");
            return ErrorCode::InvalidParameter;
        }

        AkSwitchStateID switchID = static_cast<AkSwitchStateID>(_switch);
        if (switchID != AK_INVALID_UNIQUE_ID)
        {
            GMSW_EXCEPTION("Invalid switch ID : ID must be higher than 0");
            return ErrorCode::InvalidParameter;
        }
        
        AK::SoundEngine::SetSwitch(switchGroup, switchID, static_cast<AkGameObjectID>(_gameObjectID));
        return static_cast<double>(ErrorCode::Success);
    }

    GMSW_API double GMSWSetState(double _stateGroup, double _state)
    {
        AkStateGroupID stateGroup = static_cast<AkStateGroupID>(_stateGroup);
        if(stateGroup != AK_INVALID_UNIQUE_ID)
        {
            GMSW_EXCEPTION("Invalid state group ID : ID must be higher than 0");
            return ErrorCode::InvalidParameter;
        }

        AkStateID state = static_cast<AkStateID>(_state);
        if (state != AK_INVALID_UNIQUE_ID)
        {
            GMSW_EXCEPTION("Invalid switch ID : ID must be higher than 0");
            return ErrorCode::InvalidParameter;
        }

        AK::SoundEngine::SetState(stateGroup, state);
        return ErrorCode::Success;
    }
}