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
/// Set the root folder of the banks.
/// 
/// argument0 relative path of the folder where the bank are.
///
/// return:
///    - Success
///    - IO if base path is null
////////////////////////////////////////////////////////
return external_call(global.dll_GMSWSetBasePath, argument0);
