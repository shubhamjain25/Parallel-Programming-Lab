#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char** argv){

    int i, sum=0, n=100;
    #pragma omp parallel
    {
        #pragma omp sections
        {
            printf("Thread: %d\n",omp_get_thread_num());
        }
        #pragma omp sections
        {
            printf("Thread: %d",omp_get_thread_num());
        }
    }

    // printf("Reduction Sum: %d\tExpected Sum: %d",sum,((n+1)*n)/2);


    return 0;
}