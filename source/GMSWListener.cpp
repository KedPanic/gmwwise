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
#include "GMSWListener.h"

extern "C"
{
    // Set a listener's position.
    GMSW_API double GMSWSetListenerPosition(double _posX, double _posY, double _posZ, double _orientationX, double _orientationY, double _orientationZ, double _index)
	{
		AkListenerPosition listenerPosition;
		listenerPosition.Position.X = static_cast<float>(_posX);
		listenerPosition.Position.Z = static_cast<float>(_posY);
		listenerPosition.Position.Y = static_cast<float>(_posZ);
		listenerPosition.OrientationFront.X = static_cast<float>(_orientationX);
		listenerPosition.OrientationFront.Z = static_cast<float>(_orientationY);
		listenerPosition.OrientationFront.Y = static_cast<float>(_orientationZ);

		AK::SoundEngine::SetListenerPosition(listenerPosition, static_cast<AkUInt32>(_index));

		return ErrorCode::Success;
	}

    // Set a game object's active listeners.
    GMSW_API double GMSWSetActiveListeners(double _gameObjectID, double _listenerMask)
    {
        AK::SoundEngine::SetActiveListeners(static_cast<AkGameObjectID>(_gameObjectID), static_cast<AkUInt32>(_listenerMask));

        return ErrorCode::Success;
    }

    // Set the scaling factor for a listener.
    GMSW_API double GMSWSetListenerScalingFactor(double _listenerIndex, double _listenerScalingFactor)
    {
        if(AK::SoundEngine::SetListenerScalingFactor(static_cast<AkUInt32>(_listenerIndex), static_cast<AkReal32>(_listenerScalingFactor)) != AK_Success)
        {
            return ErrorCode::InvalidParameter;
        }
        
        return ErrorCode::Success;
    }
}
