#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

long steps = 1000000;

// Gregory-Leibniz series
// https://www.csc.tntech.edu/pdcincs/resources/modules/plugged/pi_estimation/Pi%20Estimation.pdf

int main (int argc, char *argv[]) {

    int i,j;
    double x;
    double pi, sum;
    // Compute parallel compute times for 1-MAX_THREADS
    // for (j=1; j<= MAX_THREADS; j++) {    

    #pragma omp parallel private(sum) shared(pi) num_threads(8)  
    {       
        sum=0;
        pi=0;

        #pragma omp for
        for(long i=1;i<steps;i++){
            double val = (2*i)-1;
            if(i%2!=0){sum+=1/val;}
            else{sum-=1/val;}
        }

        #pragma omp critical
        {
            pi+=sum;
        }
        

    }
    
    printf("PI = %f \n", pi*4);

}