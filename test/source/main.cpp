/*===========================================
  GRRLIB (GX Version)

  ESIEA Wii Project
  ============================================*/

#include <grrlib.h>
#include <wiiuse/wpad.h>
#include <stdlib.h> 
#include "movement.h"

//Fonts in Data files
#include "font_png.h"
#include "pointer_png.h"

GXRModeObj* IR_Init(){
    GXRModeObj *rmode = NULL;
    rmode = VIDEO_GetPreferredMode(NULL);
    return rmode;
}

void bMove(Button& b, ir_t irPointer){
    // Moves the button with a Wiimote
    // If button goes outside of the screen, replaces it inside
    if(irPointer.y + b.height > maxY)
        b.y = maxY - b.height;
    else
        b.y = irPointer.y;
}

int main() {

    // Initializing GRRLIB
    GRRLIB_Init();

    // Initializing Wiimotes
    WPAD_Init();
    // IR init
    rmode = VIDEO_GetPreferredMode(NULL);
    GXRModeObj *rmode = IR_Init();
    WPAD_SetVRes(WPAD_CHAN_ALL,rmode->fbWidth,rmode->xfbHeight);
    WPAD_SetDataFormat(WPAD_CHAN_0,WPAD_FMT_BTNS_ACC_IR);

    //IR pointer
    ir_t irPointer;

    // Data textures
    GRRLIB_texImg * texFont = GRRLIB_LoadTexture(font_png);
    GRRLIB_InitTileSet(texFont, 8, 16, 0);
    GRRLIB_texImg* pointer = GRRLIB_LoadTexture(pointer_png);
    GRRLIB_SetMidHandle(pointer,true);

    // Objects
    Button left;
    left.initButton(0, maxY/2, 15, 60);
    Button right;
    right.initButton(maxX-15, maxY/2, 15, 60);	
    Circle move;
    move.initCircle(maxX/2, maxY/2, 10);

    // Globals variables
    bool finProgramme = false;	
    int pass = 0;
    float b=0.0;
    float speed = 3;
    int scoreL = 0;
    int scoreR = 0;

    while (!finProgramme){


        WPAD_ScanPads();  //Scan wiimotes
        WPAD_IR(WPAD_CHAN_0, &irPointer);

        if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) finProgramme = true;

        //==================== DRAW START ========================
        GRRLIB_Rectangle(left.x, left.y, left.width, left.height, 0xFF0000FF, 1);
        GRRLIB_Rectangle(right.x, right.y, right.width, right.height, 0x00FF00FF, 1);
        GRRLIB_Circle(move.x, move.y, move.radius, CLR_WHITE, 2);	  
        //GRRLIB_DrawImg(irPointer.x, irPointer.y, pointer, 0, 1, 1, CLR_WHITE);

        //GRRLIB_DrawImg(0,0,titlescreen,0,1,1,CLR_UNKNOW);
        char* posX =(char*)malloc(sizeof(char));
        char* posY =(char*)malloc(sizeof(char));
        char* showScoreL = (char*)malloc(sizeof(char));
        char* showScoreR = (char*)malloc(sizeof(char));
        sprintf(posX,"%.3f",irPointer.x);
        sprintf(posY,"%.3f",irPointer.y);
        sprintf(showScoreL, "%d", scoreL);
        sprintf(showScoreR, "%d", scoreR);
        GRRLIB_Printf(20 + 15, 16 + 15, texFont, CLR_WHITE, 2, posX);
        GRRLIB_Printf(20 + 15, 16 + 60, texFont, CLR_WHITE, 2, posY);
        GRRLIB_Printf(300, 50, texFont, 0xFF0000FF, 2, showScoreL);
        GRRLIB_Printf(340, 50, texFont, 0x00FF00FF, 2, showScoreR);
        free(posX);
        free(posY);
        free(showScoreL);
        free(showScoreR);
        GRRLIB_Render();
        //================== DRAW END ==============================

        // Calculate the new positions, speeds, etc…
        isMoving(move, right, left, pass, speed, b);

        // Move the player's pointer
        bMove(right, irPointer);
        // Move the IA player
        ia(left, move, speed);

        // If the ball reaches one side of the screen,
        // Start a new game and count the points !
        if(move.x - move.radius > maxX) {
            scoreL += 1;
            move.x = maxX/2;
            move.y = maxY/2;
            b = 0.0;
            pass = 0;
            speed = 3;
        }
        if (move.x + move.radius < 0) {
            scoreR += 1;
            move.x = maxX/2;
            move.y = maxY/2;
            b = 0.0;
            pass = 0;
            speed = 3;
        }
    }

    // Clean memory
    GRRLIB_Exit();

    exit(0);
}
