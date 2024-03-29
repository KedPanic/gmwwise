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

////////////////////////////////////////////////////////
/// Unregister all game objects.
///
/// returns: Always returns Success
///
/// Remarks:
/// Registering a game object twice does nothing. Unregistering it once unregisters it no 
/// 			matter how many times it has been registered. Unregistering a game object while it is 
/// 			in use is allowed, but the control over the parameters of this game object is lost.
/// 			For example, if a sound associated with this game object is a 3D moving sound, it will 
/// 			stop moving once the game object is unregistered, and there will be no way to recover 
/// 			the control over this game object.
////////////////////////////////////////////////////////
return external_call(global.dll_GMSWUnregisterAllGameObj);
