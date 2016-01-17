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

#ifndef GMSW_ERRORCODE_H
#define GMSW_ERRORCODE_H

namespace ErrorCode
{
    /// @enum List of error code.
    enum
    {
        Success = 0,		    ///< No error
        Failed = -1,            ///< Something failed.
        InvalidParameter = 1,	///< Bad arguments        
        IO, 				    ///< I/O error
        Bank,				    ///< Bank related error.
    };
}

#endif // GMSW_ERRORCODE_H
