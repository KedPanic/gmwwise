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
/// Set the position of a game object.
/// warning The object's orientation vector must be normalized.
///
/// - argument0 Game Object ID
/// - argument1 Position X
/// - argument2 Position Y
/// - argument3 Position Z
/// - argument4 Orientation X
/// - argument5 Orientation Y
/// - argument6 Orientation Z
///
/// returns:
/// - Success when successful
/// - InvalidParameter if parameters are not valid.
////////////////////////////////////////////////////////
external_call(global.dll_GMSWSetPosition, argument0, argument1, argument2, argument3, argument4, argument5, argument6);
