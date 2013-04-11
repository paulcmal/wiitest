#include "personnage.h"

// using namespace std;

Personnage::Personnage()
{
   life=10;
   saute = false;
   etage=0;
   plan = 2;
   view = LOOK_RIGHT;
   projectiles=NULL; // Trolololol
}
