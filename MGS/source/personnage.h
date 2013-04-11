#ifndef PERSONNAGE_H
#define PERSONNAGE_H

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
   int etage;  // 0(rdc), 1 ou 2
   int plan;  // 1, 2 ou 3
   
   // il serait plus logique de mettre ce qui suit dans la classe ingame vu que ce n'est pas spécifique à un perso
   // mais je l'ai mis dans les attributs de Snake car c'est plus facile d'accéder aux attributs de Snake
   // plutôt qu'aux attributs de ingame
   bool view;  // cf define
   float debutDraw;  // abscisse absolue du point du decor le plus a gauche dessiné (utile pour dessiner les balles...etc)
   cell* projectiles; //WTF ?!
   
   
   
};

#endif
