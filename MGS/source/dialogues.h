#ifndef DIALOGUES_H
#define DIALOGUES_H

#define DIAL_1 "Alors, Snake, tu as réussi à t'infiltrer ?"
#define DIAL_2 "La routine, quoi..."
#define DIAL_3 "Mais tu ne m'as toujours pas dit ce que je fais ici."
#define DIAL_4 "Ton objectif est d'infiltrer l'ESIEA."
#define DIAL_5 "L'ESIEA ?"
#define DIAL_6 "D'après nos renseignement, ils auraient crée un tank furtif capable de lancer des ogives nucléaires"
#define DIAL_6B " n'importe où dans le monde."
#define DIAL_7 "Un autre Metal Gear ?!"
#define DIAL_8 "Snake, tu dois les en empêcher."
#define DIAL_9 "Comme d'hab..."
#define DIAL_10 "Tu dois neutraliser le Metal Gear."
#define DIAL_11 "Le nom de code de l'opération est \"Checkmate\" (échec et mat)"
#define DIAL_11B "car ils ont appelé leur Metal Gear \"Kasparov\"."
#define DIAL_12 "Comme le joueur d'échec..."
#define DIAL_13 "Exactement."
#define DIAL_14 "Tu devras peut-être neutraliser les responsables du projet avant de détruire le Metal Gear."
#define DIAL_14B "Leur équipe se compose de: \
Pierre Schott: expert en electronique. \
Eric Konieczny: expert en robotique. "
#define DIAL_14C "Sylvie Zago: experte en physique. \
Hubert Wassner: expert en informatique."
#define DIAL_15 "Let's go !"

// pour Snake
#define MACRO_DIAL_S  { \
WPAD_ScanPads();\
if(WPAD_ButtonsDown(0) & WPAD_BUTTON_A)\
   return;\
GRRLIB_DrawImg(0, 0, codec1, 0, 1, 1, 0xFFFFFFFF);\
draw_dialogue(dial);\
GRRLIB_Render();}

// pour Campbell
#define MACRO_DIAL_C  { \
WPAD_ScanPads();\
if(WPAD_ButtonsDown(0) & WPAD_BUTTON_A)\
   return;\
GRRLIB_DrawImg(0, 0, codec2, 0, 1, 1, 0xFFFFFFFF);\
draw_dialogue(dial);\
GRRLIB_Render();}

#endif
   
