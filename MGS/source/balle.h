#ifndef BALLE_H
#define BALLE_H

#include "def.h"

class Balle{
 public:
  float x;
  float y;
  float xrelatif;
  float speed;
  Balle();

 private:
  GRRLIB_texImg* picBalle;
};

#endif
