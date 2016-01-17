////////////////////////////////////////////////////////
//  Enregistrement d'un plugin wwise.
// - argument0 Type de plugin.
// - Renvoie  0 ou un code d'erreur.
//
// List des types:
// 0 Sine
// 1 Tone Generator
// 2 Silence
// 3 Audio Input
// 4 Delay
// 5 Parametric EQ
// 6 Matrix Reverb
// 7 Compressor
// 8 Expander
// 9 Peak Limiter
// 10 Roomverb.
////////////////////////////////////////////////////////
external_call(global.dll_GMWRegisterPlugin, argument0);