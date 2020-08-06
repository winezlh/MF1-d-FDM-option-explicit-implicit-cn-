#include "CNMethod.h"
#include <cmath>

CNMethod::CNMethod(ParabPDE* PtrPDE_,int imax_,int jmax_)
         : ImplicitScheme(PtrPDE_, imax_, jmax_)
{
}

double CNMethod::A(int i, int j)
{
    return 0.5*dt*(b(i-0.5,j)/2.0-a(i-0.5,j)/dx)/dx;
}

double CNMethod::B(int i, int j)
{
    return 1.0+0.5*dt*(2.0*a(i-0.5,j)/(dx*dx)-c(i-0.5,j));
}


double CNMethod::C(int i, int j)
{
    return -0.5*dt*(b(i-0.5,j)/2.0+a(i-0.5,j)/dx)/dx;
}

double CNMethod::D(int i, int j)
{
    return -dt*d(i-0.5,j);
}

double CNMethod::E(int i, int j)
{
    return -A(i,j);
}

double CNMethod::F(int i, int j)
{
    return 2.0-B(i,j);
}

double CNMethod::G(int i, int j)
{
    return -C(i,j);
}
