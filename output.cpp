#include "output.h"
using namespace netCDF;

/*
Function for taking vector b and outputting to netCDF file
*/
void output(rvector<double> b, rvector<double> eps){

    //Initialize netCDF file Potential.nc
    NcFile* dataFile = new NcFile("Potential.nc", NcFile::replace); 

    // Create dimension x which has the length of b
    NcDim x = dataFile->addDim("x", b.size());

    // Create a variable V, which is a double dependent on x
    NcVar V = dataFile->addVar("V", ncDouble, x);
    NcVar e = dataFile->addVar("epsilon", ncDouble, x);

    // Assign variable V to be b
    V.putVar(&b[0]);
    e.putVar(&eps[0]);

    delete dataFile;
}