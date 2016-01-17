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
/// Set a listener's position.
///
/// - argument0 Position X.
/// - argument1 Position Y.
/// - argument2 Position Z.
/// - argument3 Orientation X.
/// - argument4 Orientation Y.
/// - argument5 Orientation Z.
/// - argument6 Listener Index.
///
/// returns: Always Success
////////////////////////////////////////////////////////
external_call(global.dll_GMSWSetListenerPosition, argument0, argument1, argument2, argument3, argument4, argument5, argument6);
