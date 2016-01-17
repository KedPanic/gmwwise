////////////////////////////////////////////////////////
// Chargement de la banque.
// - argument0 Nom de la banque.
// - Renvoie l'identifiant de la banque sinon un code d'erreur.
////////////////////////////////////////////////////////
return external_call(global.dll_GMWLoadBank, argument0);