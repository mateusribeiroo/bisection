#include <stdio.h>

double function(double x){
    return x*x-2;
}

int main(){
    double b, a, half, eps;
    unsigned long KMAX, k = 0;

    printf("Please input the initial range a, b\n");
    scanf("%lf", &a);
    scanf("%lf", &b);
    printf("Now insert the error precision\n");
    scanf("%lf", &eps);
    printf("Insert the max number of iterations you want\n");
    scanf("%d", &KMAX);

    while(k < KMAX && a-b > eps){
        if(function(a)*function(half) < 0){
            b = half;
        }else{
            a = half;
        }

        k++;
    }

    if(KMAX == k){
        printf("Program stoped cause k reached the max number of iterations");
    }else{
        printf("The root is %lf", half);
    }

    return 0;
}