#pragma once

#include <iostream>

class Vecteur2D{
    public:
    Vecteur2D(): Vecteur2D(0.0,0.0){}          //constructeur par defaut qui met à (0,0)
    Vecteur2D(double nx, double ny): x(nx),y(ny){}  // constructeur de la classe Vecteur2D


    bool operator==(Vecteur2D const & a);           //test egalité entre deux vecteurs
    Vecteur2D operator~();                          //retourne le vecteur unitaire du vecteur courant
    bool operator!=(Vecteur2D const & a);           //retourne true si les vecteurs sont differents à une precision de 1e-10
    void operator+=(Vecteur2D const & a);           //ajoute au vecteur le vecteur a
    void operator-=(Vecteur2D const & a);           //soustrait au vecteur le vecteur a
    void operator=(Vecteur2D const & a);            //affecte à un vecteur la valeur du vecteur a
    void affiche() const;                                //affiche le vecteur
    void set_coord(double modifx, double modify );      //modifie les coordonnées du vecteur
    bool compare(Vecteur2D a) const;                    //compare deux vecteurs à une à une  précision 1e-10
    double getX() const{
        return x;
    }
    double getY() const{
        return y;
    }
    void setX(double a)
    {
        x=a;
    }
    void setY(double b)
    {
        y=b;
    }
    //Vecteur2D addition(Vecteur2D autre) const;
    //Vecteur2D soustraction(Vecteur2D autre) const;
    //Vecteur2D oppose() const;
    //Vecteur2D mult(double a) const;
    //double prod_scal (Vecteur2D autre) const;
    double norme() const;                                   //norme usuelle
    double norme2();                                  // norme au carré
    //Vecteur2D unitaire() const;


    private:
    double x;
    double y;

};
std::ostream& operator<<(std::ostream& sortie, const Vecteur2D& vect);   //permet de pouvoir faire cout d'un vecteur
const Vecteur2D operator+(Vecteur2D u, Vecteur2D const & v);            //additione le vecteur u et v
const Vecteur2D operator-(Vecteur2D u, Vecteur2D const & v);            //soustrait le vecteur u et v
double operator*(Vecteur2D a, Vecteur2D b);                             //produit scalaire de a et b
Vecteur2D operator*(Vecteur2D v, double a);
Vecteur2D operator*(double a,Vecteur2D v);        //Pour qu'on puisse faire l'opération dans l'ordre que l'on veut

