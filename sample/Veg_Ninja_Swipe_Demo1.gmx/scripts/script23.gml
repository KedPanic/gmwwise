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
/// Post an event to the sound engine by ID.
///
/// - argument0 Unique ID of the event.
/// - argument1 Associated game object ID.
/// 
/// returns: The playing ID of the event launched or an error code.
////////////////////////////////////////////////////////
return external_call(global.dll_GMSWSetAttenuationScalingFactor, argument0, argument1);
