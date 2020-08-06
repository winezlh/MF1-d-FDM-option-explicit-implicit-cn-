#include <iostream>
#include "BSModel01.h"
#include "Option.h"
#include "BSEq.h"
#include "ExplicitMethod.h"
#include "Matrix.h"
#include "ImplicitScheme.h"
#include "CNMethod.h"
#include "ImplicitMethod.h"

int main()
{
double S0=100.0, r=0.05, sigma=0.2;
BSModel Model(S0,r,sigma);

double K=100.0, T=1./12., zl=0.0, zu=2.0*S0;
Put EuropeanPut(K,T,zl,zu);

BSEq BSPDE(&Model,&EuropeanPut);

int imax=3000, jmax=1000;

ExplicitMethod Method1(&BSPDE, imax, jmax);

Method1.EXSolvePDE();

imax=200, jmax=3000;

ImplicitMethod Method2(&BSPDE, imax, jmax);
Method2.SolvePDE();

CNMethod Method3(&BSPDE, imax, jmax);
Method3.SolvePDE();

cout << "By using Explicit Method, Price = " << Method1.v(0.0,S0) << endl;
cout << "By using Implicit Method, Price = " << Method2.v(0.0,S0) << endl;
cout << "By using CN Method, Price = " << Method3.v(0.0,S0) << endl;

return 0;
}
