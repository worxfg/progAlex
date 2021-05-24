#include<iostream>
#include<cmath>
#include "ciel.h"
#include <vector>
#include <array>
using namespace std;

Ciel::Ciel(const ChampPotentiels& champ, double vinf) : Boite(champ.getLx(), champ.getLy(), champ.getLz(), champ.getlambda()) {
    for(int i(0); i< Lx/lambda+1; ++i){
     std::vector<std::vector<CubedAir>> tab1;
        for(int j(0); j<Ly/lambda+1; ++j){
            std::vector<CubedAir> tab2;

            for(int k(0); k<Lz/lambda+1; ++k){
                tab2.push_back(CubedAir(champ.vitesse(i,j,k,vinf)));

            }
            tab1.push_back(tab2);

        }
        tabcubedair.push_back(tab1);

}


}

Ciel::Ciel(double Lx, double Ly, double Lz, double lambda, double v_x, double v_y, double v_z): Boite (Lx, Ly, Lz, lambda){
    for(int i(0); i< Lx/lambda+1; ++i){
     std::vector<std::vector<CubedAir>> tab1;

        for(int j(0); j<Ly/lambda+1; ++j){
            std::vector<CubedAir> tab2;    //tableau avec les données parcourant les z pour x et y fixés

            for(int k(0); k<Lz/lambda+1; ++k){
                CubedAir cube(std::array<double,3>({v_x, v_y, v_z}));
                tab2.push_back(cube);
            }
            tab1.push_back(tab2);
        }
        tabcubedair.push_back(tab1);
}
}

CubedAir Ciel::getCube(int i, int j, int k ) const{
    return tabcubedair[i][j][k];
}

void Ciel::calcul_nuage(double cte, double P_inf, double T_inf, double tx_humidite){
    int compteur(0);
    for(int i(0); i<Lx/lambda+1; ++i){
        for(int j(0); j<Ly/lambda+1; ++j){
            for(int k(0); k<Lz/lambda+1; ++k){
                tabcubedair[i][j][k].calcul_h(cte, k*lambda);
                tabcubedair[i][j][k].calcul_T();
               tabcubedair[i][j][k].calcul_P(P_inf, T_inf);
                tabcubedair[i][j][k].calcul_P_eau(tx_humidite);
               tabcubedair[i][j][k].calcul_P_rosee();
              tabcubedair[i][j][k].calcul_nuage();

            }
        }
    }
    ++compteur; cout<<compteur<<endl;

}

void Ciel::affiche_tout2(){
    for (int i(0); i < Lx/lambda+1; i++){
        for (int j(0); j < Ly/lambda+1; j++){
            for (int k(0); k < Lz/lambda+1; k++){
               cout << i << " " << j << " " << k << " " << tabcubedair[i][j][k].v2() << " "  <<tabcubedair[i][j][k].geth() << " "<<tabcubedair[i][j][k].getT() <<" "<<tabcubedair[i][j][k].getP() << " " << tabcubedair[i][j][k].getP_eau() << " "  << tabcubedair[i][j][k].getP_rosee()<<" "<<tabcubedair[i][j][k].getnuage() << endl;
            }
        }
    }
}
std::ostream& operator<<(std::ostream& sortie, Ciel const& a_afficher)
{
    sortie<<"un ciel :"<<endl;
    for(int i(0); i<a_afficher.getLx()/a_afficher.getlambda()+1; ++i)
    {
        for(int j(0); j<a_afficher.getLy()/a_afficher.getlambda()+1; ++j)
        {
            for(int k(0); k<a_afficher.getLz()/a_afficher.getlambda()+1; ++k)
            {
                sortie<<i<<" "<<j<<" "<<k<<" "<<a_afficher.gettabcubdair(i,j,k).v2()<<" "<<a_afficher.gettabcubdair(i,j,k).geth()<< " "<<a_afficher.gettabcubdair(i,j,k).getT()<<" ";
                sortie<<a_afficher.gettabcubdair(i,j,k).getP()<<" "<<a_afficher.gettabcubdair(i,j,k).getP_eau()<<" "<<a_afficher.gettabcubdair(i,j,k).getP_rosee()<<" "<<a_afficher.gettabcubdair(i,j,k).getnuage()<<endl;
            }
        }
    }
    return sortie;
}
