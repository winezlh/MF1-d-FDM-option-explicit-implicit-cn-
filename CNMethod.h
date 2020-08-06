#ifndef CNMethod_h
#define CNMethod_h

#include "ImplicitScheme.h"

class CNMethod: public ImplicitScheme
{
   public:
      CNMethod(ParabPDE* PtrPDE_,int imax_,int jmax_);

      double A(int i, int j);
      double B(int i, int j);
      double C(int i, int j);
      double D(int i, int j);
      double E(int i, int j);
      double F(int i, int j);
      double G(int i, int j);
};

#endif
