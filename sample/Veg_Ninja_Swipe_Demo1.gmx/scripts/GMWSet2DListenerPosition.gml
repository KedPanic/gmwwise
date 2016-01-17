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
// Definie la position du listener grï¿½ce ï¿½ 2 vecteurs
// - argument0 Position du listener sur l'axe des X.
// - argument1 Position du listener sur l'axe des Y.
// - argument2 Orientation du listener sur l'axe des X.
// - argument3 Orientation du listener sur l'axe des Y.
////////////////////////////////////////////////////////
external_call(global.dll_GMWSet2DListenerPosition, argument0, argument1, argument2, argument3);
