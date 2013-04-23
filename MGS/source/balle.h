#ifndef BALLE_H
#define BALLE_H

#include "def.h"

class Balle{
 public:
  float x;
  float y;
  float xdir;
  float ydir;
  float speed;
  Balle();

 private:
  GRRLIB_texImg* picBalle;
};

#endif
