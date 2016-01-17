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
/// Reset the value of the game parameter to its default value, as specified in the Wwise project.
/// With this function, you may reset a game parameter to its default value on global scope or on game object scope. 
/// Game object scope supersedes global scope. Game parameter values reset on global scope are applied to all 
/// game objects that were not overriden with a value on game object scope.
/// To reset a game parameter value on global scope, pass AK_INVALID_GAME_OBJECT as the game object. 
/// With this function, you may also reset the value of a game parameter over time. To do so, specify a non-zero 
/// value for in_uValueChangeDuration. At each audio frame, the game parameter value will be updated internally 
/// according to the interpolation curve. If you call SetRTPCValue() or ResetRTPCValue() with in_uValueChangeDuration = 0 in the 
/// middle of an interpolation, the interpolation stops and the new value is set directly. 
///
/// - argument0 Rtpc ID
/// - argument1 Game Object ID
/// - argument2 Value change duration
/// - argument3 Fade Curve
/// - argument4 Bypass internal value interpolation
///
/// returns: Always Success
////////////////////////////////////////////////////////
external_call(global.dll_GMSWResetRTPCValue, argument0, argument1, argument2, argument3, argument4);
