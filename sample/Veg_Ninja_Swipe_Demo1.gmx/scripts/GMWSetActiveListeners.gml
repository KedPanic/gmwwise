// Definie les listeners actifs pour un "game object" donne.
// gameObjectID Identifiant du "game object".
// listener Bitmask pour activer/desactiver.
// Renvoie toujours 0.
//
// exemple : 5 -> 0101 -> seulement le listener 1 et 3 sont actif
// avec le gameObjectID specifie.
// GMW_API double STDCALL GMWSetActiveListeners(double gameObjectID, double listenerBitmask);

// Normalement vous n'avez pas besoin d'y toucher pour un usage classique. 

external_call(global.dll_GMWSetActiveListeners, argument0, argument1);
