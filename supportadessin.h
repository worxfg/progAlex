#pragma once

class Montagne;
class Ciel;
class ChampPotentiels;
class Systeme;

class SupportADessin
{
 public:
  virtual ~SupportADessin() = default;
  // on ne copie pas les Supports
  SupportADessin(SupportADessin const&)            = delete;
  SupportADessin& operator=(SupportADessin const&) = delete;
   // mais on peut les déplacer
  SupportADessin(SupportADessin&&)            = default;
  SupportADessin& operator=(SupportADessin&&) = default;

  SupportADessin() = default;

  /* Mettre ici toutes les méthodes nécessaires pour dessiner tous les
   * objets que l'on veut dessiner. Par exemple :
   *    virtual void dessine(Nounours const& a_dessiner) = 0;
   *    virtual void dessine(Voiture  const& a_dessiner) = 0;
   */
          virtual void dessine(Montagne const& a_dessiner) = 0;
          virtual void dessine(Ciel const& a_dessiner) = 0;
          virtual void dessine(ChampPotentiels const& a_dessiner) = 0;
          virtual void dessine(Systeme const& a_dessiner) = 0;
};
