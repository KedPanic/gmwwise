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

#ifndef GMSW_GAMESYNCS_H
#define GMSW_GAMESYNCS_H

extern "C"
{
    /// Set the value of a real-time parameter control (by ID).
    /// With this function, you may set a game parameter value on global scope or on game object scope. 
    /// Game object scope supersedes global scope. Game parameter values set on global scope are applied to all 
    /// game objects that not yet registered, or already registered but not overriden with a value on game object scope.
    /// To set a game parameter value on global scope, pass AK_INVALID_GAME_OBJECT as the game object. 
    /// Note that busses ignore RTPCs when they are applied on game object scope. Thus, you may only change bus 
    /// or bus plugins properties by calling this function with AK_INVALID_GAME_OBJECT.
    /// With this function, you may also change the value of a game parameter over time. To do so, specify a non-zero 
    /// value for in_uValueChangeDuration. At each audio frame, the game parameter value will be updated internally 
    /// according to the interpolation curve. If you call SetRTPCValue() with in_uValueChangeDuration = 0 in the 
    /// middle of an interpolation, the interpolation stops and the new value is set directly. Thus, if you call this 
    /// function at every game frame, you should not use in_uValueChangeDuration, as it would have no effect and it is less efficient.
    ///
    /// @return Always Success
    GMSW_API double GMSWSetRTPCValue(double _rtpcID, double _rtpcValue, double _gameObjectID, double _valueChangeDuration, double _fadeCurve, double _bypassInternalValueInterpolation);

    /// Set the value of a real-time parameter control (by ID).
    /// With this function, you may set a game parameter value on playing id scope. 
    /// Playing id scope supersedes both game object scope and global scope. 
    /// Note that busses ignore RTPCs when they are applied on playing id scope. Thus, you may only change bus 
    /// or bus plugins properties by calling SetRTPCValue() with AK_INVALID_GAME_OBJECT.
    /// With this function, you may also change the value of a game parameter over time. To do so, specify a non-zero 
    /// value for in_uValueChangeDuration. At each audio frame, the game parameter value will be updated internally 
    /// according to the interpolation curve. If you call SetRTPCValueByPlayingID() with in_uValueChangeDuration = 0 in the 
    /// middle of an interpolation, the interpolation stops and the new value is set directly. Thus, if you call this 
    /// function at every game frame, you should not use in_uValueChangeDuration, as it would have no effect and it is less efficient.
    ///
    /// @return Always Success
    GMSW_API double GMSWSetRTPCValueByPlayingID(double _rtpcID, double _rtpcValue, double _playingID, double _valueChangeDuration, double _fadeCurve, double _bypassInternalValueInterpolation);

    /// Get the value of a real-time parameter control (by ID).
    /// 
    /// @return
    ///     - RTPC value if succes
    ///     - InvalidParameter if the id doesn't exist.
    ///     - Failed if another error occurred.
    GMSW_API double GMSWGetRTPCValue(double _rtpcID, double _gameObjectID);

    /// Reset the value of the game parameter to its default value, as specified in the Wwise project.
    /// With this function, you may reset a game parameter to its default value on global scope or on game object scope. 
    /// Game object scope supersedes global scope. Game parameter values reset on global scope are applied to all 
    /// game objects that were not overriden with a value on game object scope.
    /// To reset a game parameter value on global scope, pass AK_INVALID_GAME_OBJECT as the game object. 
    /// With this function, you may also reset the value of a game parameter over time. To do so, specify a non-zero 
    /// value for in_uValueChangeDuration. At each audio frame, the game parameter value will be updated internally 
    /// according to the interpolation curve. If you call SetRTPCValue() or ResetRTPCValue() with in_uValueChangeDuration = 0 in the 
    /// middle of an interpolation, the interpolation stops and the new value is set directly. 
    ///
    /// @return Always Success
    GMSW_API double GMSWResetRTPCValue(double _rtpcID, double _gameObjectID, double _valueChangeDuration, double _fadeCurve, double _bypassInternalValueInterpolation);

    /// Set the state of a switch group (by IDs).
    ///
    /// @return Always returns Success
    GMSW_API double GMSWSetSwitch(double _switchGroup, double _switchID, double _gameObjectID);

    /// @brief Set state of the specified group.
    /// 
    /// @param _dStateGroup ID of the group.
    /// @param _dState New value to set.
    /// 
    /// @return 0 or an error code.
    GMSW_API double GMSWSetState(double _stateGroup, double _state);
}

#endif // GMSW_GAMESYNCS_H

