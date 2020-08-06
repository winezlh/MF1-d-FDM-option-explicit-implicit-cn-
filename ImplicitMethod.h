#ifndef ImplicitMethod_h
#define ImplicitMethod_h

#include "ImplicitScheme.h"

class ImplicitMethod: public ImplicitScheme
{
   public:
      ImplicitMethod(ParabPDE* PtrPDE_,int imax_,int jmax_);

      double A(int i, int j);
      double B(int i, int j);
      double C(int i, int j);
      double D(int i, int j);
      double E(int i, int j);
      double F(int i, int j);
      double G(int i, int j);
};

#endif
