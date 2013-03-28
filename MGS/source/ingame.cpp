#include "ingame.h"
#include <decor01_png.h>
#include <decor02_png.h>
#include <decor03_png.h>
#include <decor04_png.h>
#include <decor05_png.h>
#include <decor06_png.h>
#include <decor07_png.h>
#include <decor08_png.h>
#include <perso_png.h>


Ingame::Ingame()
{
   decor01=GRRLIB_LoadTexture(decor01_png);
   decor02=GRRLIB_LoadTexture(decor02_png);
   decor03=GRRLIB_LoadTexture(decor03_png);
   decor04=GRRLIB_LoadTexture(decor04_png);
   decor05=GRRLIB_LoadTexture(decor05_png);
   decor06=GRRLIB_LoadTexture(decor06_png);
   decor07=GRRLIB_LoadTexture(decor07_png);
   decor08=GRRLIB_LoadTexture(decor08_png);
   perso=GRRLIB_LoadTexture(perso_png);
   //Personnage Snake;
}

void Ingame::initSnake(Personnage& Snake){
  Snake.x = 100;
  Snake.y = 400;
  Snake.life = 10;
  Snake.saute = false;
}

void Ingame::moveSnake(Personnage& Snake)
{
  WPAD_ScanPads();
  if(WPAD_ButtonsHeld(WPAD_CHAN_0) & WPAD_BUTTON_RIGHT && Snake.x < 640 )     
    Snake.x+=3;
  if(WPAD_ButtonsHeld(WPAD_CHAN_0) & WPAD_BUTTON_LEFT && Snake.x > 0)
    Snake.x-=3;

  //Saut de Snake
  if(!Snake.saute && Snake.y < 400)
    Snake.y += 3;
  if(Snake.saute && Snake.y > 250)
    Snake.y -= 3;
  if(Snake.y == 250)
    Snake.saute = false;
  if(WPAD_ButtonsHeld(WPAD_CHAN_0) & WPAD_BUTTON_UP && Snake.y == 400)
    Snake.saute = true;
}

void Ingame::drawDecor(Personnage Snake)
{
   if(Snake.x<320)
   {
      GRRLIB_DrawImg(0,0,decor01,0,1,1,CLR_WHITE);
   }
   if(Snake.x>=320 && Snake.x<960)  // pendant le passage dans ce if, (Snake.x+320)%640 va de 0 à 639
   {
      GRRLIB_DrawPart(0,0,(Snake.x+320)%640,0,640-((Snake.x+320)%640),480,decor01,0,1,1,CLR_WHITE);
      GRRLIB_DrawPart(640-((Snake.x+320)%640),0,0,0,(Snake.x+320)%640,480,decor02,0,1,1,CLR_WHITE);
   }
   if(Snake.x>=960 && Snake.x<1600)
   {
      GRRLIB_DrawPart(0,0,(Snake.x+320)%640,0,640-((Snake.x+320)%640),480,decor02,0,1,1,CLR_WHITE);
      GRRLIB_DrawPart(640-((Snake.x+320)%640),0,0,0,(Snake.x+320)%640,480,decor03,0,1,1,CLR_WHITE);
   }
   if(Snake.x>=1600 && Snake.x<2240)
   {
      GRRLIB_DrawPart(0,0,(Snake.x+320)%640,0,640-((Snake.x+320)%640),480,decor03,0,1,1,CLR_WHITE);
      GRRLIB_DrawPart(640-((Snake.x+320)%640),0,0,0,(Snake.x+320)%640,480,decor04,0,1,1,CLR_WHITE);
   }
   if(Snake.x>=2240 && Snake.x<2880)
   {
      GRRLIB_DrawPart(0,0,(Snake.x+320)%640,0,640-((Snake.x+320)%640),480,decor04,0,1,1,CLR_WHITE);
      GRRLIB_DrawPart(640-((Snake.x+320)%640),0,0,0,(Snake.x+320)%640,480,decor05,0,1,1,CLR_WHITE);
   }
   if(Snake.x>=2880 && Snake.x<3520)
   {
      GRRLIB_DrawPart(0,0,(Snake.x+320)%640,0,640-((Snake.x+320)%640),480,decor05,0,1,1,CLR_WHITE);
      GRRLIB_DrawPart(640-((Snake.x+320)%640),0,0,0,(Snake.x+320)%640,480,decor06,0,1,1,CLR_WHITE);
   }
   if(Snake.x>=3520 && Snake.x<4160)
   {
      GRRLIB_DrawPart(0,0,(Snake.x+320)%640,0,640-((Snake.x+320)%640),480,decor06,0,1,1,CLR_WHITE);
      GRRLIB_DrawPart(640-((Snake.x+320)%640),0,0,0,(Snake.x+320)%640,480,decor07,0,1,1,CLR_WHITE);
   }
   if(Snake.x>=4160 && Snake.x<4800)
   {
      GRRLIB_DrawPart(0,0,(Snake.x+320)%640,0,640-((Snake.x+320)%640),480,decor07,0,1,1,CLR_WHITE);
      GRRLIB_DrawPart(640-((Snake.x+320)%640),0,0,0,(Snake.x+320)%640,480,decor08,0,1,1,CLR_WHITE);
   }
   if(Snake.x>=4800)
   {
      GRRLIB_DrawImg(0,0,decor08,0,1,1,CLR_WHITE);
   }   
}



void Ingame::drawPlayer(Personnage Snake)
{
  GRRLIB_DrawImg(Snake.x,Snake.y,perso,0,1,1,CLR_WHITE);
}

void Ingame::destructeur()
{
   GRRLIB_FreeTexture(decor01);
   GRRLIB_FreeTexture(decor02);
   GRRLIB_FreeTexture(decor03);
   GRRLIB_FreeTexture(decor04);
   GRRLIB_FreeTexture(decor05);
   GRRLIB_FreeTexture(decor06);
   GRRLIB_FreeTexture(decor07);
   GRRLIB_FreeTexture(decor08);
}

