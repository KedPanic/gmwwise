#include "GMWListener.h"

extern "C"
{
	//----------------------------------------------------------------
	// Definie la position du listener. ------------------------------
	double GMWSet2DListenerPosition(double pos_x, double pos_y, double o_x, double o_y)
	{
		return GMWSet3DListenerPosition(pos_x, pos_y, 0.f, o_x, o_y, 0.f);
	}

	//----------------------------------------------------------------
	// Definie la position du listener. ------------------------------
	double GMWSet3DListenerPosition(double pos_x, double pos_y, double pos_z, double o_x, double o_y, double o_z)
	{
		AkListenerPosition listenerPosition;
		listenerPosition.Position.X = static_cast<float>(pos_x);
		listenerPosition.Position.Z = static_cast<float>(pos_y);
		listenerPosition.Position.Y = static_cast<float>(pos_z);
		listenerPosition.OrientationFront.X = static_cast<float>(o_x);
		listenerPosition.OrientationFront.Z = static_cast<float>(o_y);		
		listenerPosition.OrientationFront.Y = static_cast<float>(o_z);

		AK::SoundEngine::SetListenerPosition(listenerPosition);

		return EC_NONE;
	}

   double GMWSetActiveListeners(double gameObjectID, double listenerID)
   {
       AK::SoundEngine::SetActiveListeners(static_cast<AkGameObjectID>(gameObjectID), static_cast<AkUInt32>(listenerID));

       return EC_NONE;
   }
}