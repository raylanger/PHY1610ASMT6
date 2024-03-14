#include "output.h"
using namespace netCDF;

/*
Function for taking vector b and outputting to netCDF file
*/
void output(rvector<double> b){

    //Initialize netCDF file Potential.nc
    NcFile* dataFile = new NcFile("Potential.nc", NcFile::replace); 

    // Create dimension x which has the length of b
    NcDim x = dataFile->addDim("x", b.size());

    // Create a variable V, which is a double dependent on x
    NcVar data = dataFile->addVar("V", ncDouble, x);
    
    // Assign variable V to be b
    data.putVar(&b[0]);

    delete dataFile;
}