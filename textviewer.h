#pragma once

#include <iostream>
#include "supportadessin.h"

class TextViewer : public SupportADessin {
public:
 TextViewer()
  {}
  virtual ~TextViewer() = default;
  // on ne copie pas les TextViewer
  TextViewer(TextViewer const&)            = delete;
  TextViewer& operator=(TextViewer const&) = delete;
   // mais on peut les déplacer
  TextViewer(TextViewer&&)            = default;
  TextViewer& operator=(TextViewer&&) = default;

  virtual void dessine(Systeme const& a_dessiner) override;
  virtual void dessine(Montagne const& a_dessiner) override;
  virtual void dessine(ChampPotentiels const& a_dessiner) override;
  virtual void dessine(Ciel const& a_dessiner) override;

private:
};
