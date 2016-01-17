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
/// Register a plug-in with the sound engine and set the callback functions to create the 
/// plug-in and its parameter node.
/// 
/// usage:
/// - argument0 Id of the plugin
/// 
/// returns: 0 or error code.
/// 
/// remarks
/// Supported plugin list:
/// - 0 Sine
/// - 1 Tone Generator
/// - 2 Silence
/// - 3 Audio Input
/// - 4 Delay
/// - 5 Parametric EQ
/// - 6 Matrix Reverb
/// - 7 Compressor
/// - 8 Expander
/// - 9 Peak Limiter
/// - 10 Roomverb.
/// - 11 Pitch Shifter
/// - 12 Meter
////////////////////////////////////////////////////////
external_call(global.dll_GMSWRegisterPlugin, argument0);
