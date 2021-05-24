#include "boite.h"
#include "array"


bool Boite::bord(int n, int L_i) const{
    //ici L_i reprensente la longeur de la boite selon un ceraint axe L_X=0, L_y=1 ou L_Z=2
    bool resultat(false);
    if ( ((n==0)or(n==L_i/lambda+1))){resultat=true;}

    return resultat;

}

