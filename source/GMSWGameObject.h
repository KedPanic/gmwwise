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

#ifndef GMSW_GAME_OBJECT_H
#define GMSW_GAME_OBJECT_H

extern "C"
{
	/// Register a game object.
	/// 
	/// @param _gameObjectID ID of the game object to register.
	/// 
	/// @return
    /// - Success if successful
    ///	- Fail if the specified AkGameObjectID is invalid (0 and -1 are invalid)
    GMSW_API double  GMSWRegisterGameObj(double _gameObjectID);

	/// Unregister a game object..
	///
	/// @param _gameObjectID ID of the game object to remove.
	/// 
	/// @return
    /// - Success if successful
    ///	- Fail if the specified AkGameObjectID is invalid (0 is an invalid ID)
    ///
    /// @remark Registering a game object twice does nothing. Unregistering it once unregisters it no 
    ///			matter how many times it has been registered. Unregistering a game object while it is 
    ///			in use is allowed, but the control over the parameters of this game object is lost.
    ///			For example, say a sound associated with this game object is a 3D moving sound. This sound will 
    ///			stop moving when the game object is unregistered, and there will be no way to regain control over the game object.
	GMSW_API double  GMSWUnregisterGameObj(double _gameObjectID);

    
    /// Unregister all game objects.
    ///
    /// @return Always returns Success
    ///
    /// @remark Registering a game object twice does nothing. Unregistering it once unregisters it no 
    ///			matter how many times it has been registered. Unregistering a game object while it is 
    ///			in use is allowed, but the control over the parameters of this game object is lost.
    ///			For example, if a sound associated with this game object is a 3D moving sound, it will 
    ///			stop moving once the game object is unregistered, and there will be no way to recover 
    ///			the control over this game object.
    GMSW_API double GMSWUnregisterAllGameObj();

    /// Set the position of a game object.
    /// @warning The object's orientation vector must be normalized.
    ///
    /// @return 
    /// - Success when successful
    /// - InvalidParameter if parameters are not valid.
	GMSW_API double GMSWSetPosition(double _gameObjectID, double _posX, double _posY, double _posZ, double _dirX, double _dirY, double _dirZ);

    /// Set the scaling factor of a game object.
    /// Modify the attenuation computations on this game object to simulate sounds with a a larger or smaller area of effect.
    ///
    /// @return 
    /// - Success when successful
    /// - InvalidParameter if the scaling factor specified was 0 or negative.
    GMSW_API double GMSWSetAttenuationScalingFactor(double _gameObjectID, double _attenuationScalingFactor);
}

#endif // GMSW_GAME_OBJECT_H
