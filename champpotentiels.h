#pragma once

#include "string"
#include "array"
#include <iostream>
#include <vector>
#include "cubedair.h"
#include "champpotentiels.h"
#include "boite.h"
#include "supportadessin.h"
#include "dessinable.h"
#include "potentiel.h"
#include "montagne.h"


typedef std::vector<std::vector<std::vector<Potentiel>>> tableau3D;

class ChampPotentiels: public Boite, public Dessinable
{
public:

    virtual void dessine_sur(SupportADessin& support)const override
    { support.dessine(*this); }
    void initialise(double vinf, const Montagne&);
    void calcule_laplaciens(const Montagne&);
    Vecteur2D Calcul_potentiel_vent(Montagne const& m , double vent, int i , int j , int k);
    void affiche_Potentiels()const;
    void affiche_Laplaciens();
    void affiche_potentiels_et_vent(double v);
    double erreur() const;
    void resolution(double seuil_erreur, int max_iteration,Montagne const& m, bool verbeuse=false);
    std::array<double,3> vitesse(int i,int j,int k, double v) const;
    std::array<double, 3> vitesse(int i, int j, int k) const;
double norme_vent(int i, int j, int k , double v );


 ChampPotentiels(std::array<double,3>longueur={0.0,0.0,0.0}, std::array<int,3>nb={0,0,0}):Boite(longueur,nb){} //initialise les longueurs des côtés et le pas d'échantillonage
ChampPotentiels(double Lx, double Ly, double Lz, double lambda):Boite(Lx,Ly,Lz,lambda){}



    void settabPotentiels(tableau3D ntab)
    {
        tabPotentiels=ntab;
    }
    tableau3D gettabPotentiels() const{
        return tabPotentiels;
    }
    Potentiel gettabPotentiels(int i, int j, int k) const
    {
        return tabPotentiels[i][j][k];
    }

    void iteration();

private:

    tableau3D tabPotentiels;


};
std::ostream& operator<<(std::ostream& sortie, ChampPotentiels const& a_afficher);



