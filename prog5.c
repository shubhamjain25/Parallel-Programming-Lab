#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char** argv){

    int ps, ts;
    #pragma omp parallel private(ps) shared(ts)
    {
        ps=0;
        ts=0;
        #pragma omp for
        for(int i=1;i<=100;i++){
                ps+=i;
            }

        #pragma omp critical
        {
            ts+=ps;
        }
    }

    printf("Total Sum: %d",ts);


    return 0;
}