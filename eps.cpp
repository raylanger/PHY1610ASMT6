#include "eps.h"

/*
Function for calculating epsilon(x) = 1.0+10.0*cos^2(2*pi*x) on discretized grid
*/
double epsilon(double x){

    return 1.0 + 10.0*std::pow(std::cos(2*M_PI*x),2.0);
}

rvector<double> get_eps(int N){

    double dx = 1.0/N;

    rvector<double> eps(N+1);

    double x = 0;
    for(int i = 0; i < N+1; i ++){
        eps[i] = epsilon(x);
        x += dx;
    }

    return eps;
}