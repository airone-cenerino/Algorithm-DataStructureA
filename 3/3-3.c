# include<stdio.h>
# include<string.h>
# include<stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    unsigned long long n = 0;;
    unsigned long long i = 0;
    unsigned long long ans = 0;
    scanf("%llu", &n);

    unsigned long long nSquare = n*n;

    for(i=0;i<n;i++){
        unsigned long long tmp = nSquare-i*i;
        ans += sqrtl(tmp);
        printf("i=%llu, ans=%llu\n", i, ans);
    }
    ans *= 4;
    ans++;

    printf("%llu:%.15f\n", n, (double)ans/n/n);

    // long double finalanswer = ans/n;
    // printf("%d:%.15Lf\n", n, finalanswer);
    // finalanswer /= (double)n;
    // printf("%d:%.15Lf\n", n, finalanswer);

    return 0;
}