#include "eps.h"

/*
Function for calculation epsilon(x) = 1.0+10.0*cos^2(2*pi*x)
*/
double epsilon(double x){

    return 1.0 + 10.0*std::pow(std::cos(2*M_PI*x),2.0);
}