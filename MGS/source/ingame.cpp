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
#include <balle_png.h>
#include <sprite12_png.h>



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
   balle=GRRLIB_LoadTexture(balle_png);
   tex_sprite_png = GRRLIB_LoadTexture(sprite12_png);
   //Personnage Snake;
}

void Ingame::initSnake(Personnage& Snake){  // Pourquoi pas dans le constructeur de la classe Perso ???
  Snake.x = MARGE_G;
  Snake.y = 400;
  Snake.life = 10;
  Snake.saute = false;
}

void Ingame::moveSnake(Personnage& Snake, vector<Balle>& b, ir_t irPointer)
{
  //Deplacement lateral
  WPAD_ScanPads();
  if(WPAD_ButtonsHeld(WPAD_CHAN_0) & WPAD_BUTTON_RIGHT && Snake.x < 4930) {
    Snake.x+=3.0;
    Snake.view=LOOK_RIGHT;
  }
  if(WPAD_ButtonsHeld(WPAD_CHAN_0) & WPAD_BUTTON_LEFT && Snake.x > 5) {
    Snake.x-=3.0;
    Snake.view=LOOK_LEFT;
  }

  //Changement de Plan
  if(WPAD_ButtonsHeld(WPAD_CHAN_0) & WPAD_BUTTON_PLUS && Snake.plan < 3)
    Snake.plan++;
  if(WPAD_ButtonsHeld(WPAD_CHAN_0) & WPAD_BUTTON_MINUS && Snake.plan > 1)
    Snake.plan--;

  //Calcul du x relatif (entre 0 et 640)
  if(Snake.x < MARGE_G)
    Snake.xrelatif = Snake.x;
  if(Snake.x >= MARGE_G && Snake.x <= 5120-MARGE)
    Snake.xrelatif = MARGE_G;
  if(Snake.x > 5120-MARGE)  // longueur totale moins marge à droite
    Snake.xrelatif = 640 - (5120 - Snake.x);
  
  //Tir
  if(WPAD_ButtonsHeld(0) & WPAD_BUTTON_DOWN){
    Balle balle;
    balle.x = Snake.xrelatif + 150;
    balle.y = Snake.y - 200;
    balle.xdir = irPointer.x;
    balle.ydir = irPointer.y;
    if(b.back().x - balle.x > 100 || b.size() == 0) //fréquence en mode cheat (ou shit pour ceux qui préferent)
      b.push_back(balle);
  }

  //Saut de Snake
  float saut = ((Snake.y-250)/100);
  if(saut <= 0.8)
    saut = 0.8;
  if(Snake.y <= 260)
    saut = 0.3;

  //Limite verticale pour Snake
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
   // if(Snake.etage==0) {
   if(Snake.x<MARGE_G)
   {
      GRRLIB_DrawImg(0,0,decor01,0,1,1,CLR_WHITE);
      Snake.debutDraw=0;
   }
   if(Snake.x>=640-MARGE && Snake.x<1280-MARGE)  // pendant le passage dans ce if, (Snake.x+MARGE)%640 va de 0 à 639
   {
      GRRLIB_DrawPart(0,0,(int)(Snake.x+MARGE)%640,0,640-((int)(Snake.x+MARGE)%640),480,decor01,0,1,1,CLR_WHITE);
      GRRLIB_DrawPart(640-((int)(Snake.x+MARGE)%640),0,0,0,(int)(Snake.x+MARGE)%640,480,decor02,0,1,1,CLR_WHITE);
      Snake.debutDraw=((int)Snake.x+MARGE)%640;
   }
   if(Snake.x>=1280-MARGE && Snake.x<1920-MARGE)
   {
      GRRLIB_DrawPart(0,0,(int)(Snake.x+MARGE)%640,0,640-((int)(Snake.x+MARGE)%640),480,decor02,0,1,1,CLR_WHITE);
      GRRLIB_DrawPart(640-((int)(Snake.x+MARGE)%640),0,0,0,(int)(Snake.x+MARGE)%640,480,decor03,0,1,1,CLR_WHITE);
      Snake.debutDraw=960+((int)Snake.x+MARGE)%640;
   }
   if(Snake.x>=1920-MARGE && Snake.x<2560-MARGE)
   {
      GRRLIB_DrawPart(0,0,(int)(Snake.x+MARGE)%640,0,640-((int)(Snake.x+MARGE)%640),480,decor03,0,1,1,CLR_WHITE);
      GRRLIB_DrawPart(640-((int)(Snake.x+MARGE)%640),0,0,0,(int)(Snake.x+MARGE)%640,480,decor04,0,1,1,CLR_WHITE);
      Snake.debutDraw=1600+((int)Snake.x+MARGE)%640;
   }
   if(Snake.x>=2560-MARGE && Snake.x<3200-MARGE)
   {
      GRRLIB_DrawPart(0,0,(int)(Snake.x+MARGE)%640,0,640-((int)(Snake.x+MARGE)%640),480,decor04,0,1,1,CLR_WHITE);
      GRRLIB_DrawPart(640-((int)(Snake.x+MARGE)%640),0,0,0,(int)(Snake.x+MARGE)%640,480,decor05,0,1,1,CLR_WHITE);
      Snake.debutDraw=2240+((int)Snake.x+MARGE)%640;
   }
   if(Snake.x>=3200-MARGE && Snake.x<3840-MARGE)
   {
      GRRLIB_DrawPart(0,0,(int)(Snake.x+MARGE)%640,0,640-((int)(Snake.x+MARGE)%640),480,decor05,0,1,1,CLR_WHITE);
      GRRLIB_DrawPart(640-((int)(Snake.x+MARGE)%640),0,0,0,(int)(Snake.x+MARGE)%640,480,decor06,0,1,1,CLR_WHITE);
      Snake.debutDraw=2880+((int)Snake.x+MARGE)%640;
   }
   if(Snake.x>=3840-MARGE && Snake.x<4480-MARGE)
   {
      GRRLIB_DrawPart(0,0,(int)(Snake.x+MARGE)%640,0,640-((int)(Snake.x+MARGE)%640),480,decor06,0,1,1,CLR_WHITE);
      GRRLIB_DrawPart(640-((int)(Snake.x+MARGE)%640),0,0,0,(int)(Snake.x+MARGE)%640,480,decor07,0,1,1,CLR_WHITE);
      Snake.debutDraw=3520+((int)Snake.x+MARGE)%640;
   }
   if(Snake.x>=4480-MARGE && Snake.x<5120-MARGE)
   {
      GRRLIB_DrawPart(0,0,(int)(Snake.x+MARGE)%640,0,640-((int)(Snake.x+MARGE)%640),480,decor07,0,1,1,CLR_WHITE);
      GRRLIB_DrawPart(640-((int)(Snake.x+MARGE)%640),0,0,0,(int)(Snake.x+MARGE)%640,480,decor08,0,1,1,CLR_WHITE);
      Snake.debutDraw=4160+((int)Snake.x+MARGE)%640;
   }
   if(Snake.x>=5120-MARGE)
   {
      GRRLIB_DrawImg(0,0,decor08,0,1,1,CLR_WHITE);
      Snake.debutDraw=4800;
   }   
}



void Ingame::drawPlayer(Personnage Snake,unsigned int& wait, unsigned int& direction,unsigned int& direction_new,int& left,int& top,int& frame)
{ 
  u32 wpadheld;
  
  // GRRLIB_DrawImg(Snake.xrelatif,Snake.y-240 - 48+Snake.plan*24,perso,0,1,1,CLR_WHITE);
  WPAD_ScanPads();
  GRRLIB_InitTileSet(tex_sprite_png, 24, 32, 0);
  wpadheld = WPAD_ButtonsHeld(0);
   // Draw a sprite
  GRRLIB_DrawTile(320+left, 240+top, tex_sprite_png, 0, 2, 2, CLR_WHITE, frame);
  if(GRRLIB_RectOnRect(320+left, 240+top, 48, 64, 618, 434, 12, 30))
  {
    WPAD_Rumble(WPAD_CHAN_0, 1);
  }
  if(direction_new != direction) {
    // Direction has changed, modify frame immediately
    direction = direction_new;
    frame = direction;
    wait = 0;
  }
  wait++;
  if(wait > 10) {
    // wait is needed for the number of frame per second to be OK
    wait = 0;
    if(wpadheld & WPAD_BUTTON_LEFT || wpadheld & WPAD_BUTTON_RIGHT ) {
      frame++;
    }
    else {
      frame = direction + 1;  // Not moving
      wait = 10;      // Ready to move
    }
    if(frame > (int)direction+2) frame = (int)direction;
  }




  if(wpadheld & WPAD_BUTTON_LEFT){
    left--;
    direction_new = TILE_LEFT;
  }
  if(wpadheld & WPAD_BUTTON_RIGHT){
    left++;
    direction_new = TILE_RIGHT;
  }
}

void Ingame::drawProjectiles(Personnage Snake, vector<Balle>& b)
{
  int n = 0;
  int vsize = (int)b.size();
  for(int i = 0; i < vsize; i++){
    b.at(i).x = b.at(i).x + 3.0;
    //b.at(i).y += 1.0;
  }
  while(n < vsize){
    Balle tmp = b.at(n);
    if(abs(tmp.x - Snake.xrelatif) > 500)
      b.erase(b.begin()+n);
    else
      GRRLIB_DrawImg(tmp.x, tmp.y, balle,0,1,1,CLR_WHITE);
    vsize = (int)b.size();
    n++;
  }
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

