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
/// Set the value of a real-time parameter control (by ID).
/// With this function, you may set a game parameter value on global scope or on game object scope. 
/// Game object scope supersedes global scope. Game parameter values set on global scope are applied to all 
/// game objects that not yet registered, or already registered but not overriden with a value on game object scope.
/// To set a game parameter value on global scope, pass AK_INVALID_GAME_OBJECT as the game object. 
/// Note that busses ignore RTPCs when they are applied on game object scope. Thus, you may only change bus 
/// or bus plugins properties by calling this function with AK_INVALID_GAME_OBJECT.
/// With this function, you may also change the value of a game parameter over time. To do so, specify a non-zero 
/// value for in_uValueChangeDuration. At each audio frame, the game parameter value will be updated internally 
/// according to the interpolation curve. If you call SetRTPCValue() with in_uValueChangeDuration = 0 in the 
/// middle of an interpolation, the interpolation stops and the new value is set directly. Thus, if you call this 
/// function at every game frame, you should not use in_uValueChangeDuration, as it would have no effect and it is less efficient.
///
/// - argument0 Rtpc ID
/// - argument1 Rtpc Value
/// - argument2 Game Object ID
/// - argument3 Value change duration
/// - argument4 Fade Curve
/// - argument5 Bypass internal value interpolation
///
/// returns: Always Success
////////////////////////////////////////////////////////
external_call(global.dll_GMSWSetRTPCValue, argument0, argument1, argument2, argument3, argument4, argument5);
