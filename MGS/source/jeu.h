#ifndef JEU_H
#define JEU_H

#include <time.h>  // pour temporiser avec time();
#include <string.h>

#include "def.h"

class Jeu
{
     public:  // méthodes
     Jeu();   // constructeur
     void intro();
     void menu();
     void codec();
     void about();
     void play();
     
     
};

#endif
