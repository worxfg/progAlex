#include <vecteur2d.h>
#include "champpotentiels.h"
#include "montagne.h"
#include "potentiel.h"
#include "cmath"
#include<iostream>
#include "ciel.h"
#include "constante.h"
#include "cubedair.h"
#include "textviewer.h"
#include "systeme.h"

using namespace std;


int main(){

    double longueur (20.0);
    double lambda(20.0/29.0);
    double v_inf(20.0);
    Montagne m(20.0,20.0,20.0,20.0/29.0,15.0, 15.0, 15.0, 5.0, 5.0);
    ChampPotentiels champ(longueur,longueur,longueur,lambda);
    Montagne* mp(&m);
    ChampPotentiels* champp(&champ);
    double P_inf=physique::P_ref;
    double T_inf=284.5;
    double tx_humidite=8e-3;
    double h_inf=3.5*physique::R*T_inf/physique::M_airsec;
    double cte=0.5*v_inf*v_inf+h_inf;
    TextViewer text;
    Systeme a(champp, mp, v_inf, cte, P_inf, T_inf, tx_humidite);
    a.demarre(text);

return 0;
}
