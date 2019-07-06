#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int lsqrt(long long int n){
    return sqrt(n);
}

int main(int argc, char const *argv[])
{
    long long int n;
    scanf("%lld", &n);

    if(n<0){
        printf("negative argument");
    }else{
        printf("%lld\n", lsqrt(n));
    }

    return 0;
}
