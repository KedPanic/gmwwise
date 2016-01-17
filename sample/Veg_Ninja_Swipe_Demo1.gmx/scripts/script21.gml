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
/// Stop the current content playing associated to the specified game object ID.
///
/// argument0 Specify a game object to stop only playback associated to the provided game object ID.
///
/// returns: 0.
////////////////////////////////////////////////////////
external_call(global.dll_GMWStopAll, argument0);
