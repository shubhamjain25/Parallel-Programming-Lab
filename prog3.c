#include <omp.h>
#include <stdio.h>

int main(){

    int i, j, n;
    int prime[1000];

    printf("Enter value of n: ");
    scanf("%d", &n);

    for(int i=1;i<=n;i++){
        prime[i]=1;
    }

    prime[1]=0;
    // n=13;
    // i=2,3
    for(i=2;i<=n;i++){
        for(j=i*i;j<=n;j++){
            if(prime[j]==1){
                prime[j]=0;
            }
        }
    }


    printf("Prime Numbers are:\n");
    for(int i=1;i<=n;i++){
        if(prime[i]==1){
            printf("%d\t",i);
        }
        
    }

    // #pragma omp parallel
    // {
    //     printf("Hello World from thread: %d\n", omp_get_thread_num());
    // }
    return 0;
}