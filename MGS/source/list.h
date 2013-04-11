#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>

struct cell
{
   int origin;  // abscisse de départ de la balle
   int x;   // abscisse temps réel
   struct cell *next;
};
typedef struct cell cell;

cell* ajouteD(int x, cell* l);    // ajoute au début de la liste
cell* ajouteF(int x, cell* l);    // ajoute à la fin de la liste
void empty(cell* l);             // désalloue la liste
int printN(int n, cell* l);      // retourne l'abscisse temps réel du N-ième élément
void changeN(int n, int x, cell* l);   // actualiser abscisse temps réel (i:numéro de cell, x:nouvelle valeur)
cell* supprN(int n, cell* l);     // supprime N-ième cellule
int count(cell* l);  // compte le nombre de cellules dans la liste

#endif
