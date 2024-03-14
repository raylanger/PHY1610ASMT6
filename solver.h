#ifndef SOLVER_H
#define SOLVER_H

#include <lapacke.h>
#include <rarray>

rvector<double> solver(rvector<double> d, rvector<double> off_d, rvector<double> b);

#endif