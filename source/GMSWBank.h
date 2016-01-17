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
#pragma once

#ifndef GMSW_BANK_H
#define GMSW_BANK_H

extern "C"
{
    /// Unload all loaded banks.
	void GMSWClearBanks();

	/// Set the root folder of the banks.
	///
	/// @param _basePath The path.
	///
	/// @return 
    ///     - Success
    ///     - IO if base path is null
	GMSW_API double GMSWSetBasePath(const char* _basePath);

	/// Load bank by name synchronously.
	/// 
	/// @param _bankName Name of the bank.
	/// 
	/// @return Id of the loaded bank or an error code.
	GMSW_API double GMSWLoadBank(const char* _bankName);

	/// Unload bank by id synchronously.
	///
	/// @param _bankId Bank to unload.
	/// 
	/// @return 0 or an error code.
	GMSW_API double GMSWUnloadBank(double _bankId);
}

#endif // GMSW_BANK_H
