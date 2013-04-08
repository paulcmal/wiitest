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

void Ingame::moveSnake(Personnage& Snake, time_t& start)
{
  WPAD_ScanPads();
  if(WPAD_ButtonsHeld(WPAD_CHAN_0) & WPAD_BUTTON_RIGHT)     
    Snake.x+=3.0;
  if(WPAD_ButtonsHeld(WPAD_CHAN_0) & WPAD_BUTTON_LEFT && Snake.x > 0)
    Snake.x-=3.0;

  //Saut de Snake
  float saut = ((Snake.y-250)/100);
  if(saut <= 0.8)
    saut = 0.8;
  if(Snake.y <= 260)
    saut = 0.3;

  //Limite pour Snake
  if(Snake.y > 400)
    Snake.y = 400.0;
  if(!Snake.saute && Snake.y < 400)
    Snake.y += saut*3.0;
  if(Snake.saute && Snake.y > 250)
    Snake.y -= saut*3.0;
  if(Snake.y <= 250)
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
     GRRLIB_DrawPart(0,0,(int)(Snake.x+320)%640,0,640-((int)(Snake.x+320)%640),480,decor01,0,1,1,CLR_WHITE);
      GRRLIB_DrawPart(640-((int)(Snake.x+320)%640),0,0,0,(int)(Snake.x+320)%640,480,decor02,0,1,1,CLR_WHITE);
   }
   if(Snake.x>=960 && Snake.x<1600)
   {
      GRRLIB_DrawPart(0,0,(int)(Snake.x+320)%640,0,640-((int)(Snake.x+320)%640),480,decor02,0,1,1,CLR_WHITE);
      GRRLIB_DrawPart(640-((int)(Snake.x+320)%640),0,0,0,(int)(Snake.x+320)%640,480,decor03,0,1,1,CLR_WHITE);
   }
   if(Snake.x>=1600 && Snake.x<2240)
   {
      GRRLIB_DrawPart(0,0,(int)(Snake.x+320)%640,0,640-((int)(Snake.x+320)%640),480,decor03,0,1,1,CLR_WHITE);
      GRRLIB_DrawPart(640-((int)(Snake.x+320)%640),0,0,0,(int)(Snake.x+320)%640,480,decor04,0,1,1,CLR_WHITE);
   }
   if(Snake.x>=2240 && Snake.x<2880)
   {
      GRRLIB_DrawPart(0,0,(int)(Snake.x+320)%640,0,640-((int)(Snake.x+320)%640),480,decor04,0,1,1,CLR_WHITE);
      GRRLIB_DrawPart(640-((int)(Snake.x+320)%640),0,0,0,(int)(Snake.x+320)%640,480,decor05,0,1,1,CLR_WHITE);
   }
   if(Snake.x>=2880 && Snake.x<3520)
   {
      GRRLIB_DrawPart(0,0,(int)(Snake.x+320)%640,0,640-((int)(Snake.x+320)%640),480,decor05,0,1,1,CLR_WHITE);
      GRRLIB_DrawPart(640-((int)(Snake.x+320)%640),0,0,0,(int)(Snake.x+320)%640,480,decor06,0,1,1,CLR_WHITE);
   }
   if(Snake.x>=3520 && Snake.x<4160)
   {
      GRRLIB_DrawPart(0,0,(int)(Snake.x+320)%640,0,640-((int)(Snake.x+320)%640),480,decor06,0,1,1,CLR_WHITE);
      GRRLIB_DrawPart(640-((int)(Snake.x+320)%640),0,0,0,(int)(Snake.x+320)%640,480,decor07,0,1,1,CLR_WHITE);
   }
   if(Snake.x>=4160 && Snake.x<4800)
   {
      GRRLIB_DrawPart(0,0,(int)(Snake.x+320)%640,0,640-((int)(Snake.x+320)%640),480,decor07,0,1,1,CLR_WHITE);
      GRRLIB_DrawPart(640-((int)(Snake.x+320)%640),0,0,0,(int)(Snake.x+320)%640,480,decor08,0,1,1,CLR_WHITE);
   }
   if(Snake.x>=4800)
   {
      GRRLIB_DrawImg(0,0,decor08,0,1,1,CLR_WHITE);
   }   
}



void Ingame::drawPlayer(Personnage Snake)
{
  if(Snake.x >= 320 && Snake.x <= 4800)
    GRRLIB_DrawImg(200,Snake.y-250 - 34+Snake.plan*17,perso,0,1,1,CLR_WHITE);
  if(Snake.x > 4800)
    GRRLIB_DrawImg(Snake.x - 4600,Snake.y-250 - 34+Snake.plan*17,perso,0,1,1,CLR_WHITE);
  if(Snake.x < 320)
    GRRLIB_DrawImg(Snake.x - 120,Snake.y-250 - 34+Snake.plan*17,perso,0,1,1,CLR_WHITE);

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

