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
/// Set the scaling factor of a game object.
/// Modify the attenuation computations on this game object to simulate sounds with a a larger or smaller area of effect.
///
/// returns:
/// - Success when successful
/// - InvalidParameter if the scaling factor specified was 0 or negative.
////////////////////////////////////////////////////////
return external_call(global.dll_GMSWSetAttenuationScalingFactor, argument0, argument1);
