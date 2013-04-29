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
   
   
   wait = TILE_DELAY;
   direction = TILE_DOWN; 
   direction_new = TILE_DOWN;
   frame = TILE_DOWN + 1;
}
