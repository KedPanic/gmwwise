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

#ifndef GMSW_CONFIG_PLF_H
#define GMSW_CONFIG_PLF_H

#define NOGDI
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <string>

#define GMSW_API __declspec(dllexport)

inline void GMSW_EXCEPTION(const char* format, ...)
{
    char msg[255];
    va_list argList;
    va_start(argList, format);
    vsprintf_s(msg, 255, format, argList);
    va_end(argList);

    MessageBox(NULL, msg, "GMSWwise Exception (version ##GMSW_VERSION_STRING)", MB_OK | MB_ICONSTOP);
}

#endif // GMSW_CONFIG_PLF_H