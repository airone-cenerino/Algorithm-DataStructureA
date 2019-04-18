#include <stdio.h>
#define _CRT_INT_MAX 2147999
#include <math.h>

int main(int argc, char const *argv[])
{
    int a;
    int b;
    int c;
    int menseki = _CRT_INT_MAX;
    int i=0;
    int ans;

    while(1){
        if(scanf("%d %d %d", &a, &b, &c) == EOF) break;

        if(a+b<=c || b+c<=c || a+c<=b){
            i++;
            continue;
        }

        if(menseki >= a* b/2 * sqrt(1-((a*a+b*b-c*c)/2/a/b) * ((a*a+b*b-c*c)/2/a/b)   )      ){
            ans = i;
            menseki = a* b/2 * sqrt(1- ((a*a+b*b-c*c)/2/a/b) * ((a*a+b*b-c*c)/2/a/b)   )  ;
        }
        i++;
    }

    printf("%d\n", ans+1);

    return 0;
}
