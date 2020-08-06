#include "ImplicitMethod.h"
#include <cmath>

ImplicitMethod::ImplicitMethod(ParabPDE* PtrPDE_,int imax_,int jmax_)
         : ImplicitScheme(PtrPDE_, imax_, jmax_)
{
}

double ImplicitMethod::A(int i, int j)
{
    return 0.0;
}

double ImplicitMethod::B(int i, int j)
{
    return 1.0;
}


double ImplicitMethod::C(int i, int j)
{
    return 0.0;
}

double ImplicitMethod::D(int i, int j)
{
    return -dt*d(i-1.0,j);
}

double ImplicitMethod::E(int i, int j)
{
    return -dt/dx*(b(i-1.0,j)/2.0-a(i-1.0,j)/dx);
}

double ImplicitMethod::F(int i, int j)
{
    return 1.0+dt*c(i-1.0,j)-2*dt*a(i-1.0,j)/(dx*dx);
}

double ImplicitMethod::G(int i, int j)
{
    return dt/dx*(b(i-1.0,j)/2+a(i-1.0,j)/dx);
}
