# include<stdio.h>
# include <string.h>
# include <stdlib.h>

int main(int argc, char const *argv[])
{
    unsigned long long num1;
    unsigned long long num2;

    scanf("%d %d", &num1, &num2);

    unsigned long long seki = num1*num2;

    if(num1<num2){
        unsigned long long tmp = num1;
        num1 = num2;
        num2 = tmp;
    }
 
    unsigned long long r = num1 % num2;
    while(r!=0){
        num1 = num2;
        num2 = r;
        r = num1 % num2;
    }
 
    printf("%llu\n", seki/num2);


    return 0;
}
