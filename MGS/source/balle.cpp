#include "balle.h"
#include <balle_png.h>

Balle::Balle(){
  speed = 3;
  picBalle=GRRLIB_LoadTexture(balle_png);
}

