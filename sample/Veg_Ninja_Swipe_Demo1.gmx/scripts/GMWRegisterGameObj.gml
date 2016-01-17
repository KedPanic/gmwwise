////////////////////////////////////////////////////////
// Enregistrement d'un "game object".
// - argument0 Identifiant du "game object".
// - argument1 Identifiant du groupe de "game object".
// - Renvoie 0 sinon une code d'erreur.
////////////////////////////////////////////////////////
return external_call(global.dll_GMWRegisterGameObj, argument0, argument1);
