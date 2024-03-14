#include "vectors.h"
#include "eps.h"

/*
Function for getting diagonal elements of matrix A given a number of space points N.
*/
rvector<double> get_d(int N){

    // Determine spatial discretization
    double dx = 1.0/N;

    //Intialist vector to hold diagonal elements
    rvector<double> d(N-1);

    // Intialize x-coordinate
    double x = 0;

    //Iterate across each element
    for (int i = 0; i < N-1; i++){
        x += dx; // Increase x by dx
        double e_p = epsilon(x + dx/2.0); // Get epsilon at x+dx/2
        double e_m = epsilon(x - dx/2.0); // Get epsilon at x-dx/2

        // Assign d[i]
        d[i] = -(e_p+e_m);
    }
    
    return d;
}

/*
Function for getting diagonal elements of matrix A given a number of space points N.
*/
rvector<double> get_offd(int N){

    // Get spatial discretization
    double dx = 1.0/N;

    //Initialize vector
    rvector<double> off_d(N-2);

    //Initialize x
    double x = 0;

    //Iterate over each element 
    for (int i = 0; i < N-2; i++){
        x += dx; //Increase x by dx

        // Assign epsilon(x+dx/2) (Utilizes fact that i-th superdiagonal will be i+1-th subdiagonal element)
        off_d[i] = epsilon(x + dx/2.0);
    }

    return off_d;
}

/*
Function for getting resultant vector given number of space points N.
*/
rvector<double> get_b(int N){

    // Determine spatial discretization
    double dx = 1.0/N;

    // Initialize vector, fill with zeros
    rvector<double> b(N-1);
    b.fill(0.0);

    // Determine x-coodinate associated with final element, add dx/2
    double x = (N-1)*dx + dx/2.0;

    // Assign -epsilon(x) to last element of b
    b[N-2] = -epsilon(x);  

    return b;
}
