#include <stdio.h>

int main()
{
    int last = -1;
    int ans0 = 0;
    int ans1 = 0;
    int renzoku = 0;
    int num = 0;

    while(scanf("%d", &num)==1){
        if(last == num){
            renzoku++;
        }else{
            renzoku = 1;
            last = num;
        }

        if(renzoku>=ans0){
            ans0=renzoku;
            ans1=num;
        }
    }

    printf("%d %d\n", ans0, ans1);

    return 0;
}