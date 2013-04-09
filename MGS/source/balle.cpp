#include "balle.h"
#include <perso_png.h>
//#include <balle_png.h>

Balle::Balle(){
  speed = 5;
  perso=GRRLIB_LoadTexture(perso_png);
}

void Balle::DrawBalle(Personnage Perso, Balle& balle){
  GRRLIB_DrawImg(Perso.xrelatif + balle.xrelatif,Perso.y-250,perso,0,1,1,CLR_WHITE);
  balle.xrelatif += balle.speed;
}
