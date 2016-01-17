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
/// Get the value of a real-time parameter control (by ID).
/// 
/// - argument0 Rtpc ID
/// - argument1 Game Object ID
///
/// returns:
///     - RTPC value if succes
///     - InvalidParameter if the id doesn't exist.
///     - Failed if another error occurred.
////////////////////////////////////////////////////////
return external_call(global.dll_GMSWGetRTPCValue, argument0, argument1);
