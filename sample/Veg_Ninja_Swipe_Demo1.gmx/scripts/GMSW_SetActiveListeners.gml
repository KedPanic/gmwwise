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
/// Set a game object's active listeners.
/// By default, all new game objects only have the listener 0 active.  Inactive listeners are not computed.
///
/// - argument0 Game object identifier 
/// - argument1 Bitmask representing the active listeners (LSB = Listener 0, set to 1 means active) 
///
/// returns: Always returns Success
////////////////////////////////////////////////////////
external_call(global.dll_GMSWSetActiveListeners, argument0, argument1);
