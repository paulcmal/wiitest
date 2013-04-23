#ifndef INGAME_H
#define INGAME_H

#include "def.h"
#include "personnage.h"
#include <time.h>
#include "balle.h"
#include <vector>



using namespace std;

class Ingame
{
 public:  // méthodes
  Ingame();   // constructeur
  void initSnake(Personnage& Snake);
  void moveSnake(Personnage& Snake, vector<Balle>& b,ir_t irPointer);
  void drawDecor(Personnage Snake);
  void drawPlayer(Personnage Snake,unsigned int& wait,unsigned int& direction,unsigned int& direction_new,int& left,int& top,int& frame);
  void drawProjectiles(Personnage Snake, vector<Balle>& b);
  void destructeur();
  
  
 private:
  GRRLIB_texImg* decor01;
  GRRLIB_texImg* decor02;
  GRRLIB_texImg* decor03;
  GRRLIB_texImg* decor04;
  GRRLIB_texImg* decor05;
  GRRLIB_texImg* decor06;
  GRRLIB_texImg* decor07;
  GRRLIB_texImg* decor08;
  GRRLIB_texImg* perso;
  GRRLIB_texImg* balle;
  GRRLIB_texImg* tex_sprite_png;
     
};

#endif
