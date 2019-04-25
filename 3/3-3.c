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


    for(i=0;i<n;i++){
        // unsigned long long tmp = sqrtl(n*n -i*i);
        // ans += tmp;
        ans += (unsigned long long)sqrtl(n*n -i*i);
    }

    int a = 1;
    double b = 0.5;

    a +=b;
    int c = a+b;

    printf("%d\n", a);
    printf("%d\n", c);


    ans *= 4;
    ans++;

    printf("%llu:%.15f\n", n, (double)ans/n/n);

    return 0;
}