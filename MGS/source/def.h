#ifndef DEF_H
#define DEF_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <grrlib.h>
#include <wiiuse/wpad.h>
#include <asndlib.h> //Permet de jouer des sons
#include <mp3player.h> //Permet d'utiliser des MP3

#define CLR_WHITE 0xFFFFFFFF
#define CLR_BLACK 0x000000FF
#define CLR_UNKNOWN 0x88888888
#define CLR_RED 0xFF0000FF
#define CLR_GREEN 0x00FF00FF
#define Xmax 640
#define Ymax 480

#define PUSH_ANY_BUTTON()   if(WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME)  break;  \
if(WPAD_ButtonsDown(0) & WPAD_BUTTON_A)  break;  \
if(WPAD_ButtonsDown(0) & WPAD_BUTTON_B)  break;  \
if(WPAD_ButtonsDown(0) & WPAD_BUTTON_1)  break;  \
if(WPAD_ButtonsDown(0) & WPAD_BUTTON_2)  break;

#endif
