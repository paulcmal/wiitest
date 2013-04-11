#include "jeu.h"
#include "dialogues.h"
#include "codec.h"
#include "ingame.h"
/*********** Images Importées *********/
#include <pic1_png.h>
#include <pic2_png.h>
#include <photo1_png.h>
#include <robot_png.h>
#include <pointer_png.h>
#include <menu1_png.h>
#include <menu2_png.h>
#include <menu3_png.h>
#include <menu4_png.h>
#include <menu5_png.h>
#include <menu6_png.h>
#include <about_png.h>
#include <codec1_png.h>
#include <codec2_png.h>
#include <font_png.h>
//#include <music01_mp3.h>



/************ METHODES DE LA CLASSE JEU **********/
Jeu::Jeu()  // constructeur
{

}

void Jeu::intro()  // ESIEA Productions
{
   GRRLIB_texImg* pic1;
   pic1=GRRLIB_LoadTexture(pic1_png);
   for (time_t t = time(0) + 3; time(0) < t; )  // tempo 5 sec
   {
      GRRLIB_DrawImg(0,0,pic1,0,1,1,0xFFFFFFFF);
      GRRLIB_Render();
   }
   GRRLIB_FreeTexture(pic1);
}
   
     
void Jeu::menu()
{
   //MP3Player_PlayBuffer(music01_mp3,music01_mp3_size,NULL);
   GRRLIB_texImg* pic2;
   pic2=GRRLIB_LoadTexture(pic2_png);
   GRRLIB_texImg* menu1;
   menu1=GRRLIB_LoadTexture(menu1_png);
   GRRLIB_texImg* menu2;
   menu2=GRRLIB_LoadTexture(menu2_png);
   GRRLIB_texImg* menu3;
   menu3=GRRLIB_LoadTexture(menu3_png);
   GRRLIB_texImg* menu4;
   menu4=GRRLIB_LoadTexture(menu4_png);
   GRRLIB_texImg* menu5;
   menu5=GRRLIB_LoadTexture(menu5_png);
   GRRLIB_texImg* menu6;
   menu6=GRRLIB_LoadTexture(menu6_png);
   
   GRRLIB_texImg* pointer = GRRLIB_LoadTexture(pointer_png);
   GRRLIB_SetMidHandle(pointer,true);  // afficher le pointeur
   ir_t irPointer;  // IR pointer*/
   bool wantToQuit=false;
   while(1)
   {
      WPAD_ScanPads();  // Scan the Wiimotes
      WPAD_IR(WPAD_CHAN_0, &irPointer);
      GRRLIB_DrawImg(0,0,pic2,0,1,1,0xFFFFFFFF);
      GRRLIB_DrawImg(270,150,menu1,0,1,1,0xFFFFFFFF);
      GRRLIB_DrawImg(270,250,menu3,0,1,1,0xFFFFFFFF);
      GRRLIB_DrawImg(270,350,menu5,0,1,1,0xFFFFFFFF);
      if(irPointer.x>270 && irPointer.x<570 && irPointer.y>150 && irPointer.y<250) // PLAY
      {
         GRRLIB_DrawImg(270,150,menu2,0,1,1,0xFFFFFFFF);
         if(WPAD_ButtonsDown(0) & WPAD_BUTTON_A)
            break;  // sortie du while -> jeu.codec()  (cf main)
      }
      if(irPointer.x>270 && irPointer.x<570 && irPointer.y>250 && irPointer.y<350)  // SETTINGS
      {
         GRRLIB_DrawImg(270,250,menu4,0,1,1,0xFFFFFFFF);
      }
      if(irPointer.x>270 && irPointer.x<570 && irPointer.y>350 && irPointer.y<450) // ABOUT
      {
         GRRLIB_DrawImg(270,350,menu6,0,1,1,0xFFFFFFFF);
         if(WPAD_ButtonsDown(0) & WPAD_BUTTON_A)
         {
            about();
         }
      }
      if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME)
      {
         wantToQuit=true;
         break;  // on sort du while(1)
      }
      GRRLIB_DrawImg(irPointer.x, irPointer.y, pointer, 0, 1, 1, 0xFFFFFFFF);
      GRRLIB_Render();
      
   }
   GRRLIB_FreeTexture(pic2);
   GRRLIB_FreeTexture(menu1);
   GRRLIB_FreeTexture(menu2);
   GRRLIB_FreeTexture(menu3);
   GRRLIB_FreeTexture(menu4);
   GRRLIB_FreeTexture(menu5);
   GRRLIB_FreeTexture(menu6);
   //MP3Player_Stop();
   if(wantToQuit==true)
   {
      GRRLIB_Exit();
      exit(0);
   }
}
    
     
void Jeu::codec()
{
   GRRLIB_texImg* photo1;
   photo1=GRRLIB_LoadTexture(photo1_png);  // idée: on voit snake dans une boite en carton qui avance vers l'entrée
   for (time_t t = time(0) + 3; time(0) < t; )  // afficher la date reelle/le lieu (voir localtime(); )
   {
      WPAD_ScanPads();
      //if(WPAD_ButtonsDown(0) & WPAD_BUTTON_A)
         //return;
      GRRLIB_DrawImg(0,0,photo1,0,1,1,CLR_WHITE);
      GRRLIB_Render();
   }
   GRRLIB_FreeTexture(photo1);
   GRRLIB_texImg* codec1;
   codec1=GRRLIB_LoadTexture(codec1_png);
   GRRLIB_texImg* codec2;
   codec2=GRRLIB_LoadTexture(codec2_png);
   //GRRLIB_texImg* texFont = GRRLIB_LoadTexture(font_png);
   //GRRLIB_InitTileSet(texFont, 8, 16, 0);
   
   char dial[200];
   
   sprintf(dial, DIAL_1);
   for(time_t t = time(0) + 3; time(0) < t; )
     MACRO_DIAL_C;
   
   sprintf(dial, DIAL_2);
   for(time_t t = time(0) + 3; time(0) < t; )
     MACRO_DIAL_S;
     
   sprintf(dial, DIAL_3);
   for(time_t t = time(0) + 3; time(0) < t; )
     MACRO_DIAL_S;
     
   sprintf(dial, DIAL_4);
   for(time_t t = time(0) + 3; time(0) < t; )
     MACRO_DIAL_C;
     
   sprintf(dial, DIAL_5);
   for(time_t t = time(0) + 3; time(0) < t; )
     MACRO_DIAL_S;
     
   sprintf(dial, DIAL_6);
   for(time_t t = time(0) + 3; time(0) < t; )
     MACRO_DIAL_C;
     
   sprintf(dial, DIAL_6B);
   for(time_t t = time(0) + 3; time(0) < t; )
     MACRO_DIAL_C;
     
   GRRLIB_texImg* robot;
   robot=GRRLIB_LoadTexture(robot_png);
   for (time_t t = time(0) + 2; time(0) < t; )
   {
      WPAD_ScanPads();
      if(WPAD_ButtonsDown(0) & WPAD_BUTTON_A)
         return;
      GRRLIB_DrawImg(0,0,robot,0,1,1,CLR_WHITE);
      GRRLIB_Render();
   }
   GRRLIB_FreeTexture(robot);
     
   sprintf(dial, DIAL_7);
   for(time_t t = time(0) + 3; time(0) < t; )
     MACRO_DIAL_S;
     
   sprintf(dial, DIAL_8);
   for(time_t t = time(0) + 3; time(0) < t; )
     MACRO_DIAL_C;
     
   sprintf(dial, DIAL_9);
   for(time_t t = time(0) + 3; time(0) < t; )
     MACRO_DIAL_S;
     
   sprintf(dial, DIAL_10);
   for(time_t t = time(0) + 3; time(0) < t; )
     MACRO_DIAL_C;
     
   sprintf(dial, DIAL_11);
   for(time_t t = time(0) + 3; time(0) < t; )
     MACRO_DIAL_C;
     
   sprintf(dial, DIAL_11B);
   for(time_t t = time(0) + 3; time(0) < t; )
     MACRO_DIAL_C;
     
   sprintf(dial, DIAL_12);
   for(time_t t = time(0) + 3; time(0) < t; )
     MACRO_DIAL_S;
     
   sprintf(dial, DIAL_13);
   for(time_t t = time(0) + 3; time(0) < t; )
     MACRO_DIAL_C;
     
   sprintf(dial, DIAL_14);
   for(time_t t = time(0) + 3; time(0) < t; )
     MACRO_DIAL_C;
     
   sprintf(dial, DIAL_14B);
   for(time_t t = time(0) + 5; time(0) < t; )
     MACRO_DIAL_C;
     
   sprintf(dial, DIAL_14C);
   for(time_t t = time(0) + 3; time(0) < t; )
     MACRO_DIAL_C;
     
   sprintf(dial, DIAL_15);
   for(time_t t = time(0) + 3; time(0) < t; )
     MACRO_DIAL_S;
   
   GRRLIB_FreeTexture(codec1);
   GRRLIB_FreeTexture(codec2);
}

void Jeu::about()
{
   GRRLIB_texImg* about;
   about=GRRLIB_LoadTexture(about_png);
   while(1)
   {
       WPAD_ScanPads();
       PUSH_ANY_BUTTON()
       GRRLIB_DrawImg(0,0,about,0,1,1,0xFFFFFFFF);
       GRRLIB_Render();
   }
   GRRLIB_FreeTexture(about);
}

void Jeu::play()
{
   Personnage Snake;
   Ingame ingame;
   ingame.initSnake(Snake);
   vector<Balle> b;
   

   GRRLIB_texImg * texFont = GRRLIB_LoadTexture(font_png);
   GRRLIB_InitTileSet(texFont, 8, 16, 0);
   /*GRRLIB_texImg* decor01;
   decor01=GRRLIB_LoadTexture(decor01_png);
   GRRLIB_texImg* decor02;
   decor02=GRRLIB_LoadTexture(decor02_png);
   GRRLIB_texImg* decor03;
   decor03=GRRLIB_LoadTexture(decor03_png);*/
   bool finProgramme = false;
   while(!finProgramme)
   {
     WPAD_ScanPads();
     if(WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) finProgramme = true;
     ingame.moveSnake(Snake,b);
     ingame.drawDecor(Snake);
     ingame.drawPlayer(Snake);
     ingame.drawProjectiles(Snake, b);



     //---------------------- TEST ----------------------------
     char* posX =(char*)malloc(sizeof(char));
     char* posY =(char*)malloc(sizeof(char));
     sprintf(posX,"%.1f",Snake.x);
     sprintf(posY,"%.1f",Snake.y);
     GRRLIB_Printf(64, 16 + 15, texFont, 0x000FFF, 2, posX);
     GRRLIB_Printf(64, 16 + 60, texFont, 0x000FFF, 2, posY);
     
     char* nb =(char*)malloc(sizeof(char));
     sprintf(nb,"%.d",count(Snake.projectiles));
     GRRLIB_Printf(64, 150, texFont, 0x000FFF, 2, nb);
     //-------------------- END TEST -------------------------
     


     GRRLIB_Render();
   }
   ingame.destructeur();
   /*GRRLIB_FreeTexture(decor01);
   GRRLIB_FreeTexture(decor02);
   GRRLIB_FreeTexture(decor03);*/
}



    
     

