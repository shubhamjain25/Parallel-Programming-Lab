#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char** argv){

    int i, sum=0, n=100;
    #pragma omp parallel for private(i) reduction(+:sum)
        for(int i=1;i<=100;i++){
            sum+=i;
        } 

    printf("Reduction Sum: %d\tExpected Sum: %d",sum,((n+1)*n)/2);


    return 0;
}