//#include "def.h"
#include "list.h"



cell* ajouteD(int i, cell* l)    // ajoute au début de la liste
{
    cell* c;
    c=(cell*)malloc(sizeof(cell));  // NB: il faut transtyper sur les mallocs car c'est du C compilé en C++
    if (c==NULL)
       return NULL;
    c->origin=i;
    c->x=i;
    c->next=l;
    return c;
}

cell* ajouteF(int i, cell* l)    // ajoute à la fin de la liste
{
   cell* d;
   d=l;
   if(d!=NULL)
   {
      while (d->next!=NULL)
      {
         d=d->next;
      }
   }
   cell* c;
   c=(cell*)malloc(sizeof(cell));
   if (c==NULL)
       return NULL;
   c->origin=i;
   c->x=i;
   c->next=NULL;
   if(d==NULL)
      return c;
   else
      d->next=c;
   return l;
}

void empty(cell* l)             // désalloue la liste
{
    cell *c;
    while(l!=NULL)
    {
        c=l;
        l=l->next;
        free(c);
     }
}

int printN(int i, cell* l)      // retourne le N-ième élément
{
    while ( i>1 && l!=NULL)
    {
       l=l->next;
       i--;
    }
    if(l==NULL)
       return -1;
    else
       return l->x;
}

void changeN(int i, int b, cell* l)   // remplacer une valeur (i:numéro de cell, b:nouvelle valeur)
{
    while ( i>1 && l!=NULL)
    {
       l=l->next;
       i--;
    }
    if(l==NULL)
       return;
    else
       l->x=b;
    return;
}


cell* supprN(int n, cell* l)     // supprime N-ième cellule
{
    if(l==NULL)  // 0 cellule
       return NULL;
    if(l->next==NULL && n==1)  // 1 cellule
       return NULL;
    if(l->next==NULL)
       return l;

    cell* tmp=l;
    while ( n>2 && (tmp->next)->next!=NULL)  // au moins 2 cellules
    {
       tmp=tmp->next;
       n--;
    }
    // n>2 pour que tmp pointe sur la cellule n-1 
    if(n>2)  // pas de N-ième cellule, (tmp->next)->next==NULL
       return l;
       
    cell* c;
    c=tmp->next;
    tmp->next=(tmp->next)->next;  // on saute la cellule à supprimer
    free(c);
    return l;
}

int count(cell* l)  // compte le nombre de cellules dans la liste
{
   if(l==NULL)
      return 0;
   int i=1;
   while(l->next!=NULL)
   {
      l=l->next;
      i++;
   }
   return i;
}


