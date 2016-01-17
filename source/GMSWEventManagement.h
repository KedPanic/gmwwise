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

#ifndef GMSW_EVENTMANAGEMENT_H
#define GMSW_EVENTMANAGEMENT_H

extern "C"
{
    /// @brief Post an event to the sound engine by ID.
    ///
    /// @param _dEventID  Unique ID of the event.
    /// @param _dGameObjectID Associated game object ID.
    /// 
    /// @return The playing ID of the event launched or an error code.
    GMSW_API double  GMSWPostEvent(double  _dEventID, double  _dGameObjectID);

    /// @brief Post the specified trigger by ID.
    /// 
    /// @param _dTriggerID ID of the trigger.
    /// @param _dGameObjectID Associated game object ID .
    ///
    /// @return 0 or an error code.
    GMSW_API double  GMSWPostTrigger(double _dTriggerID, double _dGameObjectID);

    /// @brief Stop the current content playing associated to the specified game object ID. If no game object is specified, all sounds will be stopped.
    ///
    /// @param _dGameObjectID Specify a game object to stop only playback associated to the provided game object ID. 
    ///
    /// @return 0.
    GMSW_API double GMSWStopAllByGameObject(double _dGameObjectID);

    /// @brief All sounds will be stopped.
    ///    
    /// @return 0.
    GMSW_API double GMSWStopAll();
}

#endif

