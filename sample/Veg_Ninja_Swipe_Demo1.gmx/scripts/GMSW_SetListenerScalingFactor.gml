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
/// Set the scaling factor for a listener.
/// A larger factor means that the listener will hear sounds with less attenuation based on distance.
///
/// - argument0 Listener Index
/// - argument1 Listener Scaling Factor
///
/// returns:
/// - Success when successful
/// - InvalidParameter if the scaling factor specified was 0 or negative.
////////////////////////////////////////////////////////
external_call(global.dll_GMSWSetListenerScalingFactor, argument0, argument1);
