#include "ExplicitMethod.h"

void ExplicitMethod::EXSolvePDE()
{
   for (int j=0; j<=jmax; j++) V[imax][j]=f(j);
   for (int i=imax; i>0; i--)
   {
      V[i-1][0]=fl(i-1);
      V[i-1][jmax]=fu(i-1);
      for (int j=1;j<jmax;j++)
      {
         V[i-1][j]=A(i,j)*V[i][j-1]+B(i,j)*V[i][j]
	          +C(i,j)*V[i][j+1]+D(i,j);
      }
   }
}
