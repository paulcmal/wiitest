#ifndef DEF_H
#define DEF_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <grrlib.h>
#include <wiiuse/wpad.h>
#include <asndlib.h> //Permet de jouer des sons
#include <mp3player.h> //Permet d'utiliser des MP3
#include "list.h"

#define CLR_WHITE 0xFFFFFFFF
#define CLR_BLACK 0x000000FF
#define CLR_UNKNOWN 0x88888888
#define CLR_RED 0xFF0000FF
#define CLR_GREEN 0x00FF00FF
#define Xmax 640
#define Ymax 480
#define LOOK_LEFT false
#define LOOK_RIGHT true
#define MARGE 500  // marge à droite de Snake (distance entre Snake et la droite de l'écran)
#define MARGE_G 640-MARGE


// Tile stuff
#define TILE_DELAY  10
#define TILE_UP     12*0
#define TILE_RIGHT  12*1*3
#define TILE_DOWN   12*2*3
#define TILE_LEFT   12*3*3
#define TILE_JUMPDR  12*6*3+3
#define TILE_JUMPDL  12*6*3+5
#define TILE_TIRR   12*5*3+7
#define TILE_TIRL   12*7*3+7


#define PUSH_ANY_BUTTON()   if(WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME)  break;  \
if(WPAD_ButtonsDown(0) & WPAD_BUTTON_A)  break;  \
if(WPAD_ButtonsDown(0) & WPAD_BUTTON_B)  break;  \
if(WPAD_ButtonsDown(0) & WPAD_BUTTON_1)  break;  \
if(WPAD_ButtonsDown(0) & WPAD_BUTTON_2)  break;


#endif
