#include "def.h"
#include "personnage.h"

class Balle{
 public:
  float x;
  float xrelatif;
  float speed;
  Balle();
  void DrawBalle(Personnage Perso, Balle& balle);

 private:
  GRRLIB_texImg* perso;
};
