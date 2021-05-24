#pragma once
#include "string"
#include "array"
#include <iostream>
#include <vector>

class CubedAir
{
public:
CubedAir(std::array<double,3> vent): vent(vent) {}
//CubedAir(CubedAir const& autre) : vent(autre.vent) {}            //constructeur de copie pas utile je pense a enlever plus tard

std::array<double,3> getvent() const{
        return vent;
    }
void calcul(double, double, double, double, double);
double v2() const;                                             //norme carré du vent

std::string toString(std::vector<std::string> format={"v", "h","T","P","P_eau","P_rosee","nuage"},char sep=' ') const;
double geth(){
    return h;
}
double getT(){
    return T;
}
double getP(){
    return P;
}
double getP_eau(){
    return P_eau;
}
double getP_rosee(){
    return P_rosee;
}
bool getnuage(){
    return nuage;
}
void calcul_nuage ();
void calcul_h(double, double);
void calcul_T();
void calcul_P(double, double);
void calcul_P_eau(double);
void calcul_P_rosee();

private:
 bool nuage;
 double h;
 double T;
 double P;
 double P_eau;
 double P_rosee;

 std::array<double,3> vent;                      //comportera 3 elements pour le vent dans chaque direction



};

