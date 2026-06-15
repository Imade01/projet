#include <stdio.h>
#include <stdlib.h>
#include "somme.h"

int main()
{
    TMonome* courant1 = NULL ;
    TMonome* courant2 = NULL ;
    printf("ENTREZ LE PREMIER POLYNOME\n");
    courant1 = creer_Monome(courant1);
    printf("ENTREZ LE DEUXIEME POLYNOME\n");
    courant2 = creer_Monome(courant2);

    somme_Polynome(courant1 , courant2) ;
    return 0 ;
}

