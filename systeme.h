#pragma once
#include <vector>
#include <iostream>
#include "dessinable.h"
#include "ciel.h"
#include "montagne.h"
#include "champpotentiels.h"
#include "textviewer.h"

class Systeme : public Dessinable {

    public:
    Systeme(ChampPotentiels* champ, Montagne* montagne, double vinf, double cte, double P, double T, double taux)
    : champ(champ), montagne(montagne), vinf(vinf), cte(cte), P_inf(P), T_inf(T), taux_humidite(taux)
    {
        champ->initialise(vinf, *montagne);
    }

     virtual void dessine_sur(SupportADessin& support)const override
            { support.dessine(*this); }

        Montagne getMontagne() const
        {
            return *montagne;
        }

        ChampPotentiels getChampPotentiels() const
        {
            return *champ;
        }
        Ciel getCiel() const
        {
            return *ciel;
        }
        void evolue(SupportADessin& support);
        void demarre(SupportADessin& support);

    private:

        ChampPotentiels* champ;
        Montagne* montagne;
        Ciel* ciel;
        double vinf;
        double cte;
        double P_inf;
        double T_inf;
        double taux_humidite;

};

std::ostream& operator<<(std::ostream& sortie, Systeme const& a_afficher);
