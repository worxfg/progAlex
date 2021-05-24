
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

typedef std::vector<std::vector<std::vector<CubedAir>>> tableau3D2;

class Ciel : public Boite, public Dessinable
{
public:
    virtual void dessine_sur(SupportADessin& support)const override
    { support.dessine(*this); }
    Ciel(const ChampPotentiels&, double vinf);
    Ciel (double Lx, double Ly, double Lz, double lambda, double v_x=0.0, double v_y=0.0, double v_z=0.0);
    CubedAir getCube(int, int, int) const;
    void calcul_nuage(double, double, double, double);
void affiche_tout2();

    tableau3D2 gettabcubdair() const{
        return tabcubedair;
    }
    CubedAir gettabcubdair(int i,int j, int k) const{
        return tabcubedair[i][j][k];
    }

    void affiche_ciel();



private:
    tableau3D2 tabcubedair;

};
std::ostream& operator<<(std::ostream& sortie, Ciel const& a_afficher);
