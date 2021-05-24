#pragma once
#include "boite.h"
#include "dessinable.h"
#include <iostream>

class Montagne : public Boite, public Dessinable {
    private:
    double h;
    double x_0;
    double y_0;
    double sigmax;
    double sigmay;

    public:
    Montagne(): Montagne(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0){}                                     //constructeur par defaut qui met tout à 0.0
    Montagne(double Lx, double Ly, double Lz, double lambda, double h, double x_0, double y_0, double sigmax, double sigmay):
       Boite(Lx,Ly,Lz,lambda), h(h), x_0(x_0), y_0(y_0), sigmax(sigmax), sigmay(sigmay) {}                  // constructeur de la classe Montagne

    virtual void dessine_sur(SupportADessin& support)const override
    { support.dessine(*this); }
double altitude (double x, double y)const;
double geth()const{return h;}
double getx_0()const{return x_0;}
double gety_0()const{return y_0;}
double getsigmax()const{return sigmax;}
double getsigmay()const{return sigmay;}
double getlambda()const{return lambda;}
void setlambda (double lam)
{
    lambda=lam;
}
void seth(double he)
{
    h=he;
}
void setx_0(double X_0){
     x_0=X_0;
 }
void sety_0(double Y_0){
     y_0=Y_0;
 }
void setsigmax(double Sigmax){
     sigmax=Sigmax;
 }
void setsigmay(double Sigmay){
     sigmay=Sigmay;
 }



};
std::ostream& operator<<(std::ostream& sortie, Montagne const& a_afficher);

