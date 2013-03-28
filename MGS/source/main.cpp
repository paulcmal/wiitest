/*===========================================
        MGS
============================================*/

#include "jeu.h"
#include "personnage.h"

GXRModeObj* IR_Init() {  // optimiser la vidéo (?)
    GXRModeObj *rmode = NULL;
    rmode = VIDEO_GetPreferredMode(NULL);
    return rmode;
}

int main(int argc, char **argv) {
    
    GRRLIB_Init(); // Initialise the Graphics & Video subsystem
    WPAD_Init(); // Initialise the Wiimotes
    //rmode = VIDEO_GetPreferredMode(NULL);
    GXRModeObj *rmode = IR_Init();  // IR init
    WPAD_SetVRes(WPAD_CHAN_ALL,rmode->fbWidth,rmode->xfbHeight);  // set Xmax, Ymax
    //WPAD_SetVRes(WPAD_CHAN_ALL,640,480);  // set Xmax, Ymax
    WPAD_SetDataFormat(WPAD_CHAN_0,WPAD_FMT_BTNS_ACC_IR);  // active capteur IR
    GRRLIB_SetBackgroundColour(0x00, 0x00, 0x00, 0xFF);
    
    //ASND_Init(); //On initialise le systeme de sons
    //MP3Player_Init(); //On initialise le lecteur MP3
    
    Jeu jeu;  // Création d'un objet jeu de classe Jeu
    jeu.intro();  // Lance "Esiea production"
    
    
    while(1)
    {
        jeu.menu();   // Lance menu du jeu
        jeu.codec();
        jeu.play();
        
        
    }
    
    
    GRRLIB_Exit(); // Be a good boy, clear the memory allocated by GRRLIB
    exit(0);  // Use exit() to exit a program, do not use 'return' from main()
}
