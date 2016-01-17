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
#pragma once

#ifndef GMSW_LISTENER_H
#define GMSW_LISTENER_H

extern "C"
{
    /// Set a listener's position.
    /// 
    /// @return Always Success.
	GMSW_API double  GMSWSetListenerPosition(double _posX, double _posY, double _posZ, double _orientationX, double _orientationY, double _orientationZ, double _index);

    /// Set a game object's active listeners.
    /// By default, all new game objects only have the listener 0 active.  Inactive listeners are not computed.
    ///
    /// @param _gameObjectID Game object identifier 
    /// @param _listenerMask Bitmask representing the active listeners (LSB = Listener 0, set to 1 means active) 
    ///
    /// @return Always returns Success
    GMSW_API double  GMSWSetActiveListeners(double _gameObjectID, double _listenerMask);

    /// Set the scaling factor for a listener.
    /// A larger factor means that the listener will hear sounds with less attenuation based on distance.
    ///
    /// @return 
    /// - Success when successful
    /// - InvalidParameter if the scaling factor specified was 0 or negative.
    GMSW_API double GMSWSetListenerScalingFactor(double _listenerIndex, double _listenerScalingFactor);
}

#endif // GMSW_LISTENER_H
