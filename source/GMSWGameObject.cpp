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
#include "GMSWGameObject.h"

extern "C"
{
	// Register a game object. 
    GMSW_API double GMSWRegisterGameObj(double _gameObjectID)
	{
		if(AK::SoundEngine::RegisterGameObj(static_cast<AkGameObjectID>(_gameObjectID)) != AK_Success)
		{
			GMSW_EXCEPTION("Unable to register this game object : %d", static_cast<AkGameObjectID>(_gameObjectID));

			return ErrorCode::InvalidParameter;
		}

		return ErrorCode::Success;
	}

	// Remove a game object.
    GMSW_API double GMSWUnregisterGameObj(double _gameObjectID)
	{
		if(AK::SoundEngine::UnregisterGameObj(static_cast<AkGameObjectID>(_gameObjectID)) != AK_Success)
		{
			GMSW_EXCEPTION("Unable to unregister this game object : %d", _gameObjectID);

			return ErrorCode::InvalidParameter;
		}

		return ErrorCode::Success;
	}

    // Unregister all game objects.
    GMSW_API double GMSWUnregisterAllGameObj()
	{
        AK::SoundEngine::UnregisterAllGameObj();
        return ErrorCode::Success;
	}
	
	// Set the position of the specified game object.
    GMSW_API double GMSWSetPosition(double _gameObjectID, double _posX, double _posY, double _posZ, double _dirX, double _dirY, double _dirZ)
    {
        AkSoundPosition soundPos;
        soundPos.Position.X = static_cast<float>(_posX);
        soundPos.Position.Z = static_cast<float>(_posY);
        soundPos.Position.Y = static_cast<float>(_posZ);
        soundPos.Orientation.X = static_cast<float>(_dirX);
        soundPos.Orientation.Z = static_cast<float>(_dirY);
        soundPos.Orientation.Y = static_cast<float>(_dirZ);

        if (AK::SoundEngine::SetPosition(static_cast<AkGameObjectID>(_gameObjectID), soundPos) != AK_Success)
        {
            return ErrorCode::InvalidParameter;
        }

        return ErrorCode::Success;
    }

    // Set the scaling factor of a game object.
    GMSW_API double GMSWSetAttenuationScalingFactor(double _gameObjectID, double _attenuationScalingFactor)
	{
        if(AK::SoundEngine::SetAttenuationScalingFactor(static_cast<AkGameObjectID>(_gameObjectID), static_cast<AkReal32>(_attenuationScalingFactor)) != AK_Success)
        {
            return ErrorCode::InvalidParameter;
        }

        return ErrorCode::Success;
	}
}
