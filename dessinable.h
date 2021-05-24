#pragma once
#include <iostream>
#include "supportadessin.h"

class Dessinable {
 public:

  virtual void dessine_sur(SupportADessin&)const = 0;
  virtual ~Dessinable() = default;
  Dessinable(Dessinable const&)            = default;
  Dessinable& operator=(Dessinable const&) = default;
  Dessinable(Dessinable&&)                 = default;
  Dessinable& operator=(Dessinable&&)      = default;

  Dessinable() = default;
};

