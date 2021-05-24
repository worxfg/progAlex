#include "cubedair.h"
#include "constante.h"
#include <cmath>
using namespace std;

double CubedAir::v2() const{
    return vent[0]*vent[0]+vent[1]*vent[1]+vent[2]*vent[2];
}

void CubedAir:: calcul(double cte, double z, double P_inf, double T_inf, double tx_humidite){
calcul_h(cte,z);
calcul_T();
calcul_P(P_inf,T_inf);
calcul_P_eau(tx_humidite);
calcul_P_rosee();
calcul_nuage();
}

void CubedAir::calcul_h(double cte, double z){
    h=cte-physique::g*z-0.5*v2();
}

void CubedAir::calcul_T(){
    T=2*physique::M_airsec *h/(7.0*physique::R);
}

void CubedAir::calcul_P(double P_inf, double T_inf){
    P=P_inf*(pow(T_inf,-7.0/2.0)*(pow(T,7.0/2.0)));
}

void CubedAir::calcul_P_eau(double tx_humidite){
    double rapport(0);
    rapport=(physique::M_eau/physique::M_airsec)+tx_humidite;
    P_eau=tx_humidite*P/rapport;
}

void CubedAir:: calcul_P_rosee(){
    P_rosee=physique::P_ref*std::exp(13.96-5208/T);
}

void CubedAir::calcul_nuage(){
    if(P_eau>P_rosee){
        nuage=true;
    }else{nuage=false;}
}

