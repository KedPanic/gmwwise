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
#include "GMSWEventManagement.h"

extern "C"
{
    //----------------------------------------------------------------
    // Post an event to the sound engine by ID. ----------------------
    double GMSWPostEvent(double  _eventID, double  _gameObjectID)
    {
        if (_eventID < 0)
        {
            GMSW_EXCEPTION("Bad event ID : ID must be higher or equal to 0");

            return ErrorCode::InvalidParameter;
        }

        if (_gameObjectID < 0)
        {
            GMSW_EXCEPTION("Bad game object ID : ID must be higher or equal to 0");

            return ErrorCode::InvalidParameter;
        }

        AkPlayingID id = AK::SoundEngine::PostEvent(static_cast<AkUniqueID>(_eventID), static_cast<AkGameObjectID>(_gameObjectID));
        if (id == AK_INVALID_PLAYING_ID)
        {
            GMSW_EXCEPTION("unable to post the specified event %d for the specified game object %d", _eventID, _gameObjectID);

            return ErrorCode::InvalidParameter;
        }

        return id;
    }

    //----------------------------------------------------------------
    // Post the specified trigger by ID. -----------------------------
    double GMSWPostTrigger(double _dTriggerID, double _dGameObjectID)
    {
        if (_dTriggerID < 0)
        {
            GMSW_EXCEPTION("Bad trigger ID : ID must be higher or equal to 0");

            return ErrorCode::InvalidParameter;
        }

        if (_dGameObjectID < 0)
        {
            GMSW_EXCEPTION("Bad game object ID : ID must be higher or equal to 0");

            return ErrorCode::InvalidParameter;
        }

        AK::SoundEngine::PostTrigger(static_cast<AkTriggerID>(_dTriggerID), static_cast<AkGameObjectID>(_dGameObjectID));

        return ErrorCode::Success;
    }

    //----------------------------------------------------------------
    // Stop the current content playing associated to the specified 
    // game object ID. If no game object is specified, all sounds will 
    // be stopped ----------------------------------------------------
    double GMSWStopAllByGameObject(double _dGameObjectID)
    {
        AK::SoundEngine::StopAll(static_cast<AkGameObjectID>(_dGameObjectID));

        return ErrorCode::Success;
    }


    //----------------------------------------------------------------
    // All sounds will be stopped.
    double GMSWStopAll()
    {
        AK::SoundEngine::StopAll(AK_INVALID_GAME_OBJECT);

        return ErrorCode::Success;
    }
}