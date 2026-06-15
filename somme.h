#ifndef H_POLYNOMES_H
#define H_POLYNOMES_H

typedef struct TMonome TMonome ;
struct TMonome
{
    float coeff ;
    int degre ;
    TMonome *suivant ;
};

TMonome* inserer_Monome(TMonome *courant ,float co ,float ex);

TMonome* creer_Monome(TMonome *courant) ;

void afficherPolynome(TMonome *courant);

void somme_Polynome(TMonome *poly1, TMonome *poly2);



#endif // H_POLYNOMES_H
