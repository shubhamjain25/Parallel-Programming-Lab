#include <stdio.h>
#include <omp.h>

int main(int argc, char **argv) {
    int a[5] = {1,2,3,4,5};
    int b[5] = {10,20,30,40,50};
    int c[4];
    int tid;
    int i, sum=0;
    
    omp_set_num_threads(4);

    #pragma omp parallel 
    {
        tid = omp_get_thread_num();
        c[tid] = 0;
        int sv = (tid)*25;
        printf("Value for tid: %d & Starting Value: %d\n",tid,sv);
        #pragma omp for
        for(i=sv+1;i<=sv+25;i++){
            c[tid]+=i;
        }
        printf("Value for tid: %d & c[tid]: %d\t\n",tid,c[tid]);
    }

    for(i=0;i<4;i++){
        sum+=c[i];
    }

    printf("Sum: %d",sum);
    // #pragma omp parallel for
    // for(int i=0;i<15;i++){
    //     tid = omp_get_thread_num();
    //     int gnt = omp_get_num_threads();

    //     printf("Value for tid: %d & gnt: %d\t",tid,gnt);
    //     printf("Hello World\n");
    // }

    // #pragma omp parallel num_threads(5)
    // {
    //     tid = omp_get_thread_num();
    //     int gnt = omp_get_num_threads();
    //     printf("Value for tid: %d & gnt: %d\t",tid,gnt);
    //     printf("Hello World\n");
    // }

    return 0;
}

