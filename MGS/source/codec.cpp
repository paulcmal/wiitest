#include "codec.h"
#include <fontCodec_ttf.h>


void draw_dialogue(char* tab)
{
   GRRLIB_ttfFont *myFont = GRRLIB_LoadTTF(fontCodec_ttf, fontCodec_ttf_size);
   
   //char tab[200] = texte;  // 90 caracteres max (3 lignes)
   char ligne1[31];
   char ligne2[31];
   char ligne3[31];
   char ligne4[31];
   
        // recherche des espaces pour éviter de couper un mot en 2
        // et division du dialogue sur 3 lignes
        int i; int j=0; int k=0; int l=0; int m=0; int z=0;
        while(tab[z]!='\0')  z++;  // n= nombre total de caracteres
        for(i=z; i<199; i++)
           tab[i]=' ';
        tab[199]='\n';
        
        for(i=0; i<30; i++)  // LIGNE 1
        {
           if(tab[i]==' ')
              j=i;  // recup du dernier espace pour savoir où couper
        }
        for(i=0; i<j; i++)  // on crée la ligne 1
           ligne1[i]=tab[i];
        ligne1[j]='\0';
        for(i=j+1; i<j+31; i++)  // REBELOTE LIGNE 2
        {
           if(tab[i]==' ')
              k=i;
        }
        for(i=0; i<(k-j); i++)
           ligne2[i]=tab[j+1+i];  // j+1 car on saute l'espace
        ligne2[k-j]='\0';
        for(i=k+1; i<k+31; i++)  // REBELOTE LIGNE 3
        {
           if(tab[i]==' ')
              l=i;
        }
        for(i=0; i<(l-k); i++)
           ligne3[i]=tab[k+1+i];  // k+1 car on saute l'espace
        ligne3[l-k]='\0';
        for(i=k+1; i<l+31; i++)  // REBELOTE LIGNE 4
        {
           if(tab[i]==' ')
              m=i;
        }
        for(i=0; i<(m-l); i++)
           ligne4[i]=tab[l+1+i];  // k+1 car on saute l'espace
        ligne4[m-l]='\0';
        
        
        GRRLIB_PrintfTTF(75, 265, myFont , ligne1, 28 , CLR_WHITE);
        GRRLIB_PrintfTTF(75, 295, myFont , ligne2, 28 , CLR_WHITE);
        GRRLIB_PrintfTTF(75, 325, myFont , ligne3, 28 , CLR_WHITE);
        GRRLIB_PrintfTTF(75, 355, myFont , ligne4, 28 , CLR_WHITE);
        
        
        GRRLIB_FreeTTF(myFont);
}
