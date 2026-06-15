#include <stdio.h>
#include <stdlib.h>
#include "somme.h"


TMonome* inserer_Monome(TMonome *courant ,float co, float ex)
{
    TMonome *temp ;
    TMonome *noeud = (TMonome*)malloc(sizeof(TMonome)) ;
    if (noeud == NULL)
        exit(1) ;

    noeud->coeff = co ;
    noeud->degre = ex ;
    noeud->suivant = NULL ;

    if (courant == NULL || ex > courant->degre)
    {
        noeud->suivant = courant ;
        courant = noeud ;
    }
    else
    {
        temp = courant ;
        while (temp->suivant != NULL && temp->suivant->degre >= ex)
        {
            temp = temp->suivant ;

        }
        noeud->suivant = temp->suivant ;
        temp->suivant = noeud ;
    }
    return courant ;


}

TMonome* creer_Monome(TMonome* courant)
{
    int n, i ;
    float coeff ;
    int degre ;

    printf("Entrez le nombre de termes :");
    scanf("%d",&n) ;

    for (i=0 ; i<n ; i++)
    {
        printf("Entrez le coefficient du terme %d:", i+1);
        scanf("%f",&coeff);

        printf("Entrez l'exposant du terme %d:",i+1);
        scanf("%d",&degre);

        courant = inserer_Monome(courant, coeff, degre);
    }
    return courant ;
}

void afficherPolynome(TMonome* courant)
{
    if (courant == NULL)
        printf("pas de polynome!!");
    else
    {
        TMonome* temp = courant ;
        while (temp != NULL)
        {
            printf("(%.1fx^%d)", temp->coeff, temp->degre);
            temp = temp->suivant ;
            if(temp != NULL)
                printf("+");
            else
                printf("\n");

        }
    }
}

void somme_Polynome(TMonome* courant1, TMonome* courant2)
{
    TMonome *ptr1 = courant1 ;
    TMonome *ptr2 = courant2 ;
    TMonome *courant3 = NULL ;

    while(ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->degre == ptr2->degre)
        {
            courant3 = inserer_Monome(courant3, ptr1->coeff + ptr2->coeff, ptr1->degre + ptr2->degre);
            ptr1 = ptr1->suivant ;
            ptr2 = ptr2->suivant ;

        }
        else if (ptr1->degre > ptr2->degre)
        {
            courant3 = inserer_Monome(courant3, ptr1->coeff, ptr1->degre);
            ptr1 = ptr1->suivant ;

        }
        else if (ptr1->degre < ptr2->degre)
        {
            courant3 = inserer_Monome(courant3, ptr2->coeff , ptr2->degre);
            ptr2 = ptr2->suivant ;

        }
    }
    while (ptr1 != NULL)
    {
        courant3 = inserer_Monome(courant3, ptr1->coeff, ptr1->degre);
        ptr1 = ptr1->suivant ;

    }
    while (ptr2 != NULL)
    {
        courant3 = inserer_Monome(courant3, ptr2->coeff, ptr2->degre);
        ptr2 = ptr2->suivant ;
    }
    printf("La somme du polynome est : ");
    afficherPolynome(courant3);

}
