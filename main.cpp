#include "solver.h"
#include "vectors.h"
#include "output.h"
#include <iostream>

int main(int argc, char* argv[]){

    // Set default N value
    int N = 10000;

    // Update N if argument given
    try{
        if (argc>1){
            N = std::stoi(argv[1]);
        }
    }catch(...){
        std::cout <<
                  "Computes the solution V(x) to the ODE d/dx[eps(x)V(x)] = 0 with eps(x) = 1.0+10.0*cos^2(2*pi*x), with boundary" 
                  "conditions V(0) = 0 and V(1) = 1. Finite difference scheme used, with matrix equation solved using LAPACKE_dgtsv."
                  "Final result outputted to netCDF file Potential.nc."
                  "Usage:\n"
                  "  ASMT6 [-h | --help] | [N_SPACE]\n\n";
            if (std::string(argv[1]) != "-h" and std::string(argv[1]) !="--help") {
                  std::cerr << "Error in arguments!\n";
                  return 1;
            } else
                  return 0;
    }

    // Get diagonal element vector, off-diagonal element vector, and resultant vector
    rvector<double> d = get_d(N), off_d = get_offd(N), b = get_b(N);

    // Solve Av = b 
    rvector<double> v = solver(d,off_d,b);

    //Output v to console and to netcdf file
    std::cout << v << "\n";
    output(v);

    return 0;
}