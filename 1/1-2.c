#include <stdio.h>

int main(int argc, char const *argv[])
{
    int max =0;
    scanf("%d", &max);

    int ans = 1;
    while(ans<=max){
        printf("%d\n", ans);
        ans*=3;
    }

    return 0;
}
