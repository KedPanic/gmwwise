////////////////////////////////////////////////////////
// Definie le chemin ou se trouve les banques sonores.
// - argument0 Chemin du dossier ou ce trouve les banques sonores.
// - Renvoie 0 sinon un code d'erreur.
////////////////////////////////////////////////////////
return external_call(global.dll_GMWSetBasePath, argument0);