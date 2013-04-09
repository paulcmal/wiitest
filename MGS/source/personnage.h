#include "def.h"

class Personnage
{
   public:
   Personnage();
   int life;
   float x;  // abscisse
   float y;
   float xrelatif; //abscisse dans l'écran [0-640]
   bool saute;
   int plan;
   bool view;
};
