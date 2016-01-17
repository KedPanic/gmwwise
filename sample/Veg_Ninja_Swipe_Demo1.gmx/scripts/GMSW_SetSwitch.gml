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
/// Set the state of a switch group (by IDs).
///
/// - argument0 Switch Group
/// - argument1 Switch Id
/// - argument2 Game Object ID
///
/// returns: Always returns Success
////////////////////////////////////////////////////////
external_call(global.dll_GMSWSetSwitch, argument0, argument1, argument2);
