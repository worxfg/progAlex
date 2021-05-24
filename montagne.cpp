#include <iostream>
#include <cmath>
#include "montagne.h"
using namespace std;

double Montagne::altitude(double x, double y)const
{
    double altitude(0.0);
    altitude= h*lambda*exp(-(pow((x-x_0*lambda),2))/(2*(pow(sigmax*lambda,2)))-((pow(y-(y_0*lambda-Ly/2),2))/(2*pow(sigmay*lambda,2))));
    if (altitude<0.5*lambda){altitude=0.0;}
    return altitude;
}

std::ostream& operator<<(std::ostream& sortie, Montagne const& a_afficher)
{
    sortie<<"Une montagne : "<<endl;
    sortie<<"gaussienne de paramètres : "<<endl;
    sortie<<"i0 = "<<a_afficher.getx_0()<<" (x_0 = "<<a_afficher.getx_0()*a_afficher.getlambda()<<")"<<endl;
    sortie<<"j0 = "<<a_afficher.gety_0()<<" (y_0 = "<<a_afficher.gety_0()*a_afficher.getlambda()<<")"<<endl;
    sortie<<"h = "<<a_afficher.geth()<<" (H = "<<a_afficher.geth()*a_afficher.getlambda()<<")"<<endl;
    sortie<<"Si0 = "<<a_afficher.getsigmax()<<" (Sx0 = "<<a_afficher.getsigmax()*a_afficher.getlambda()<<")"<<endl;
    sortie<<"Sj0 = "<<a_afficher.getsigmay()<<" (Sy0 = "<<a_afficher.getsigmay()*a_afficher.getlambda()<<")"<<endl;
    return sortie;
}
