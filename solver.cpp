#include "solver.h"
#include "vectors.h"
#include <iostream>

rvector<double> solver(rvector<double> d, rvector<double> off_d, rvector<double> b){

    int info;

    int N = d.size();

    rvector<double> du = off_d.copy(), dl = off_d.copy();

    info  = LAPACKE_dgtsv(LAPACK_ROW_MAJOR, N, 1,
        dl.data(), d.data(), du.data(), b.data(), 1);

    std::cout << b << "\n";

    return b;
}