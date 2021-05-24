#include <iostream>
#include <cmath>
#include "vecteur2d.h"
using namespace std;

Vecteur2D Vecteur2D::operator~()
{
    Vecteur2D g(x,y);
    return g*(1/norme());
}
bool Vecteur2D::operator==(Vecteur2D const & a)
{
    if ((abs(a.x-x)<1e-10)and (abs(a.y-y)<1e-10))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Vecteur2D::operator!=(Vecteur2D const & a)
{
    if ((abs(a.x-x)<1e-10)and (abs(a.y-y)<1e-10))
    {
        return false;
    }
    else
    {
        return true;
    }
}
Vecteur2D operator*(Vecteur2D v,double a)
{
    v.setX(v.getX()*a);
    v.setY(v.getY()*a);
    return v;
}
Vecteur2D operator*(double a,Vecteur2D v)
{
    v.setX(v.getX()*a);
    v.setY(v.getY()*a);
    return v;
}
ostream& operator<<(ostream& sortie, const Vecteur2D& vect)
{
    sortie<<vect.getX()<<" "<<vect.getY();
    return sortie;
}
const Vecteur2D operator+(Vecteur2D u, Vecteur2D const & v)
{
    u+=v;
    return u;
}
const Vecteur2D operator-(Vecteur2D u, Vecteur2D const & v)
{
    u-=v;
    return u;
}

void Vecteur2D::operator+=(Vecteur2D const & a)
{
    x+=a.x;
    y+=a.y;
}
void Vecteur2D::operator-=(Vecteur2D const & a)
{
    x-=a.x;
    y-=a.y;
}
void Vecteur2D::operator=(Vecteur2D const & a)
{
    x=a.x;
    y=a.y;
}
double operator*(Vecteur2D a,Vecteur2D b)
{
    return(a.getX()*b.getX()+a.getY()*b.getY());
}

void Vecteur2D::set_coord(double x1, double y1) {
    x=x1;
    y=y1;
}

void Vecteur2D::affiche() const{
        cout<< x << "  " <<y<<endl;
    }

bool Vecteur2D::compare(Vecteur2D a ) const{
        if ((abs(a.x-x)<1e-10)and (abs(a.y-y)<1e-10)){return true;
    }else{
        return false;}
    }

//Vecteur2D Vecteur2D::addition(Vecteur2D autre) const{
//    Vecteur2D c;
//    c.set_coord(x + autre.x, y + autre.y);
//    return c;
//}

//Vecteur2D Vecteur2D::soustraction(Vecteur2D autre) const{
//    Vecteur2D c;
//    c.set_coord(x - autre.x, y - autre.y);
//    return c;
//}

//Vecteur2D Vecteur2D::oppose() const{
//    Vecteur2D c;
//    c.set_coord(-x, -y);
//    return c;
//}

//Vecteur2D Vecteur2D::mult(double a) const{
//    Vecteur2D c;
//    c.set_coord(a*x, a*y);
//    return c;
//}

//double Vecteur2D::prod_scal(Vecteur2D autre) const{
//    double d;
//    d=x*autre.getX()+y*autre.getY();
//    return d;
//}

double Vecteur2D::norme() const{
    return sqrt(x*x+y*y);

}

double Vecteur2D::norme2() {
    return norme()*norme();
}

//Vecteur2D Vecteur2D::unitaire() const{
//    Vecteur2D g;
//    g=mult(1/norme());
//    return g;
//}
