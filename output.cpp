#include "output.h"

using namespace netCDF;

void output(rvector<double> b){
    NcFile* dataFile = new NcFile("Potential.nc", NcFile::replace); 

    NcDim len = dataFile->addDim("x", b.size());
    NcVar data = dataFile->addVar("V", ncDouble, len);
    data.putVar(&b[0]);

    delete dataFile;
}