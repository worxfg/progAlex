#pragma once

#include <vecteur2d.h>
#include <iostream>



class Potentiel
{
private:
Vecteur2D potentiel;
Vecteur2D laplacien;

public:

Potentiel(Vecteur2D a=Vecteur2D (0,0), Vecteur2D b=Vecteur2D (0,0))
    :potentiel(a), laplacien(b){}

void setPotentiel(Vecteur2D a)
{
    potentiel=a;
}
void setLaplacien(Vecteur2D b)
{
    laplacien=b;
}

Vecteur2D getPotentiel() const
{
    return potentiel;
}

Vecteur2D getLaplacien() const
{
    return laplacien;
}
};
