#include "def.h"
#include <time.h>
#include "balle.h"

class Ingame
{
 public:  // méthodes
  Ingame();   // constructeur
  void initSnake(Personnage& Snake);
  void moveSnake(Personnage& Snake, time_t& start);
  void drawDecor(Personnage Snake);
  void drawPlayer(Personnage Snake);
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
  //int Snake_x;
  //Personnage Snake;
  
     
     
};
