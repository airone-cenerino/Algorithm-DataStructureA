# include<stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    // 最初に全部確認する
    int kosuu[123456*2+1];  // iまでの素数の個数
    kosuu[0] = 0;
    kosuu[1] = 0;

    int i;
    for(i = 2;i<=123456*2;i++){   // iが素数かどうか判定する
    int flg = 0;
        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0){
                kosuu[i] = kosuu[i-1];
                flg = 1;
                break;
            }
        }
        
        if(flg==0)
            kosuu[i] = kosuu[i-1]+1;
    }

    while(1){
        int n;
        int ans=0;
        scanf("%d", &n);

        if(n==0){
            break;
        }

        printf("%d\n", kosuu[2*n]-kosuu[n]);
    }

    return 0;
}
