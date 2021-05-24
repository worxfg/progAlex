#include <iostream>
#include "systeme.h"

using namespace std;

std::ostream& operator<<(std::ostream& sortie, Systeme const& a_afficher)
{
    sortie<<"Le système est constitué de : " <<std::endl<<std::endl;
    sortie<<a_afficher.getMontagne()<<endl<<endl<<a_afficher.getChampPotentiels()<<endl<<endl<<a_afficher.getCiel()<<endl;
    return sortie;
}
void Systeme::evolue(SupportADessin& support) {
    dessine_sur(support);
}

void Systeme::demarre(SupportADessin& support) {
    champ->resolution(1e-04, 2000, *montagne);
    ciel = new Ciel(*champ,vinf);
    ciel->calcul_nuage(cte, P_inf, T_inf, taux_humidite);
    evolue(support);
}
