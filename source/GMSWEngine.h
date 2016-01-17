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
#ifndef GMSW_ENGINE_H
#define GMSW_ENGINE_H

extern "C"
{
	/// Initialization of Wwise.
	/// 
	/// @return 0 or an error code.
	/// 
	/// @remarks
	///		Have to be called in first.
	GMSW_API double GMSWInit();

	/// Shutdown Wwise and free all resources.
	///
	/// @return Always returns Success.
	///
	/// @remarks
	///		Have to be called when the game quit.
    GMSW_API double GMSWShutdown();

    /// Process all events in the sound engine's queue.
    /// This method has to be called periodically (usually once per game frame).
	/// 	
    /// @return Always returns Success
    GMSW_API double GMSWRenderAudio();	

    /// Register a plug-in with the sound engine and set the callback functions to create the 
    /// plug-in and its parameter node.
    ///
	/// @remarks
	///		Plugin list:
    ///			0 Sine
    ///			1 Tone Generator
    ///			2 Silence
    ///			3 Audio Input
    ///			4 Delay
    ///			5 Parametric EQ
    ///			6 Matrix Reverb
    ///			7 Compressor
    ///			8 Expander
    ///			9 Peak Limiter
    ///			10 Roomverb.
	///			11 Pitch Shifter
	///			12 Meter
    GMSW_API double GMSWRegisterPlugin(double _dType);

    /// Register a codec type with the sound engine and set the callback functions to create the 
    /// codec's file source and bank source nodes.
    /// 
    /// @return 
    ///     - Success if successful
    ///     - InvalidParameter if invalid parameters were provided
    ///     - Fail otherwise. Possible reasons for an Fail result are:
    ///             - Insufficient memory to register the codec
    ///             - Codec ID already registered
    ///
    /// @remarks
    /// Codecs and plug-ins must be registered before loading banks that use them.\n
    /// Loading a bank referencing an unregistered plug-in or codec will result in a load bank success,
    /// but the plug-ins will not be used. More specifically, playing a sound that uses an unregistered effect plug-in 
    /// will result in audio playback without applying the said effect. If an unregistered source plug-in is used by an event's audio objects, 
    /// posting the event will fail.    
    ///
    ///	Codecs list:
    ///		0 Vorbis
    GMSW_API double GMSWRegisterCodec(double _type);
}

#endif // GMSW_ENGINE_H
