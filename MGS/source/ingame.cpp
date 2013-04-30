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

//test push

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
  //WPAD_ScanPads();
  u32 wpadheld, wpaddown;
  wpadheld = WPAD_ButtonsHeld(0);
  wpaddown = WPAD_ButtonsDown(0);
  if(wpadheld & WPAD_BUTTON_RIGHT && Snake.x < 4930 && Snake.y == 400){
    Snake.x+=3.0;
    Snake.view=LOOK_RIGHT;
    Snake.direction_new = TILE_RIGHT;
  }
  if(wpadheld & WPAD_BUTTON_LEFT && Snake.x > 5 && Snake.y == 400){
    Snake.x-=3.0;
    Snake.view=LOOK_LEFT;
    Snake.direction_new = TILE_LEFT;
  }

  //Changement de Plan
  if(wpaddown & WPAD_BUTTON_PLUS && Snake.plan < 3 && Snake.y == 400){
    Snake.plan++;
    Snake.direction_new = TILE_DOWN;
  }
  if(wpaddown & WPAD_BUTTON_MINUS && Snake.plan > 1 && Snake.y == 400){
    Snake.plan--;
    Snake.direction_new = TILE_UP;
  }

  //Calcul du x relatif (entre 0 et 640)
  if(Snake.x < MARGE_G)
    Snake.xrelatif = Snake.x;
  if(Snake.x >= MARGE_G && Snake.x <= 5120-MARGE)
    Snake.xrelatif = MARGE_G;
  if(Snake.x > 5120-MARGE)  // longueur totale moins marge à droite
    Snake.xrelatif = 640 - (5120 - Snake.x);
  
  //Tir
  if((wpadheld & WPAD_BUTTON_DOWN)
     &&(Snake.direction == TILE_RIGHT || Snake.direction == TILE_LEFT
	|| Snake.direction == TILE_JUMPDL || Snake.direction == TILE_JUMPDR)){
    Balle balle;
    balle.x = Snake.xrelatif + 150;
    balle.y = Snake.y - 200;
    balle.xdir = Snake.direction;
    if(abs(b.back().x - balle.x) > 100 || b.size() == 0) //fréquence en mode cheat (ou shit pour ceux qui préferent)
      b.push_back(balle);
    /*if(Snake.direction == TILE_LEFT || Snake.direction == TILE_JUMPDL)
      Snake.direction_new = TILE_TIRL;
    if(Snake.direction == TILE_RIGHT || Snake.direction == TILE_JUMPDR)
    Snake.direction_new = TILE_TIRR;*/
  }

  //Saut de Snake
  float saut = ((Snake.y-250)/100);
  if(saut <= 0.8)
    saut = 0.8;
  if(Snake.y <= 260)
    saut = 0.3;

  //Limite verticale pour Snake
  if(Snake.y > 400){
    Snake.y = 400.0;
    // On change les Tiles
    if(Snake.direction == TILE_JUMPDR)
      Snake.direction_new = TILE_RIGHT;
    if(Snake.direction == TILE_JUMPDL)
      Snake.direction_new = TILE_LEFT;
  }
  if(!Snake.saute && Snake.y < 400){
    Snake.y += saut*3.0;
    if(Snake.direction == TILE_JUMPDL)
      Snake.x -= 2.0;
    if(Snake.direction == TILE_JUMPDR)
      Snake.x += 2.0;
  }
  if(Snake.saute && Snake.y > 250){
    Snake.y -= saut*3.0;
    if(Snake.direction == TILE_LEFT)
      Snake.x -= 2.0;
    if(Snake.direction == TILE_RIGHT)
      Snake.x += 2.0;
  }
  if(Snake.y <= 250){
    Snake.saute = false;
     if(Snake.direction == TILE_RIGHT)
      Snake.direction_new = TILE_JUMPDR;
    if(Snake.direction == TILE_LEFT)
      Snake.direction_new = TILE_JUMPDL;
  }
  if(WPAD_ButtonsHeld(WPAD_CHAN_0) & WPAD_BUTTON_UP && Snake.y == 400)
    Snake.saute = true;
  //Ajouter les tiles du debut de saut
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



void Ingame::drawPlayer(Personnage& Snake)
{ 
  u32 wpadheld;
  
  // GRRLIB_DrawImg(Snake.xrelatif,Snake.y-240 - 48+Snake.plan*24,perso,0,1,1,CLR_WHITE);
  GRRLIB_InitTileSet(tex_sprite_png, 24, 32, 0);
  wpadheld = WPAD_ButtonsHeld(0);
   // Draw a sprite
  GRRLIB_DrawTile(Snake.xrelatif, Snake.y -48 + Snake.plan*24, tex_sprite_png, 0, 2, 2, CLR_WHITE, Snake.frame);


  //---------------A NE PAS METTRE DANS movePlayer ----------------//
  //Sinon on ne rafraichit pas les frames correctement :)
  if(Snake.direction_new != Snake.direction) {
    // Direction has changed, modify frame immediately
    Snake.direction = Snake.direction_new;
    Snake.frame = Snake.direction;
    Snake.wait = 0;
  }
  Snake.wait++;
  if(Snake.wait > TILE_DELAY && !Snake.saute) {
    // wait is needed for the number of frame per second to be OK
    Snake.wait = 0;
    if(Snake.y == 400){
    // On prend la bonne texture en fonction de la direction
      if(wpadheld & WPAD_BUTTON_LEFT)
	Snake.frame--;
      else{
	if(wpadheld & WPAD_BUTTON_RIGHT)
	  Snake.frame++;
	else{
	  Snake.frame = Snake.direction + 1;
	  Snake.wait = 10;
	}
      }
    }
    if(Snake.frame > (int)Snake.direction+2) 
      Snake.frame = (int)Snake.direction;
    if(Snake.frame < (int)Snake.direction)
      Snake.frame = (int)Snake.direction+2;
  }
  //----------------------------------------------------------------//
}

void Ingame::drawProjectiles(Personnage Snake, vector<Balle>& b)
{
  int n = 0;
  int vsize = (int)b.size();
  for(int i = 0; i < vsize; i++){
    if(b.at(i).xdir == TILE_LEFT || b.at(i).xdir == TILE_JUMPDL)
      b.at(i).x -= 3.0;
    if(b.at(i).xdir == TILE_RIGHT || b.at(i).xdir == TILE_JUMPDR)
      b.at(i).x += 3.0;
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
   GRRLIB_FreeTexture(perso);
   
   GRRLIB_FreeTexture(balle);
   GRRLIB_FreeTexture(tex_sprite_png);
}

