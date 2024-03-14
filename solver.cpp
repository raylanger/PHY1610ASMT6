#include "solver.h"
#include "vectors.h"

/*
Function for solving Ax = b with A a symmetrical tri-diagonal matrix, given the diagonal and off-diagonal elements of A
and the resultant vector b. Returns x.
*/
rvector<double> solver(rvector<double> d, rvector<double> off_d, rvector<double> b){

    // Initialize info variable which determines successful completion of solution
    int info;

    // Determine size of matrix A
    int N = d.size();

    // Copy off_d vector into two separate vectors for subdiagonal and superdiagonal
    rvector<double> du = off_d.copy(), dl = off_d.copy();

    // Solve function for x using lapacke
    info  = LAPACKE_dgtsv(LAPACK_ROW_MAJOR, N, 1,
        du.data(), d.data(), dl.data(), b.data(), 1);

    // Return solution
    return b;
}