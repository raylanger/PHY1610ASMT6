#include "vectors.h"
#include "eps.h"


rvector<double> get_d(int N){

    double dx = 1.0/N;

    rvector<double> d(N);

    double x = 0;
    for (int i = 0; i < N; i++){
        x += dx;
        std::cout<<x<<", " << epsilon(x) << "\n";
        double e_p = epsilon(x + dx/2.0);
        double e_m = epsilon(x - dx/2.0);

        d[i] = -(e_p+e_m);
    }

    return d;
}

rvector<double> get_offd(int N){
    double dx = 1.0/N;

    rvector<double> off_d(N-1);

    double x = 0;
    for (int i = 0; i < N-1; i++){
        x += dx;

        off_d[i] = epsilon(x + dx/2.0);
    }

    return off_d;
}

rvector<double> get_b(int N){
    double dx = 1.0/N;

    rvector<double> b(N-1);
    b.fill(0.0);

    double x = (N-1)*dx + dx/2.0;

    b[N-1] = -epsilon(x); 

    return b;
}
