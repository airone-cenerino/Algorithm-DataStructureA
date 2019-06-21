# include<stdio.h>
# include <string.h>
# include <stdlib.h>

int main(int argc, char const *argv[])
{
    int i, j, n;
    char str[100][1100];
    int ans = 0;

    // 入力受け取り
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%s", &str[i]);
    }

    for(int strone=0;strone<n-1;strone++){
        for(int strtwo=strone+1;strtwo<n;strtwo++){
            // dpのメモリ確保
            int **dp;
            dp = (int**)malloc(sizeof(int*) * (strlen(str[strtwo]) + 2));
            for(i=0;i<strlen(str[strtwo])+1;i++){
                dp[i] = (int*)malloc(sizeof(int) * (strlen(str[strone]) + 2));
            }

            // dp初期化
            for(i=0;i<strlen(str[strtwo])+1;i++){
                dp[i][0] = i;
            }
            for(i=0;i<strlen(str[strone])+1;i++){
                dp[0][i] = i;
            }

            for(i=1;i<strlen(str[strtwo])+1;i++){
                for(j=1;j<strlen(str[strone])+1;j++){
                    int min = 1000;
                    if(min > dp[i-1][j]+1) min = dp[i-1][j]+1;
                    if(min > dp[i][j-1]+1) min = dp[i][j-1]+1;

                    if(str[strtwo][i-1]==str[strone][j-1]){
                        if(min > dp[i-1][j-1]) min = dp[i-1][j-1];
                    }else{
                        if(min > dp[i-1][j-1]+1) min = dp[i-1][j-1]+1;                
                    }

                    dp[i][j] = min;
                }
            }
            if(dp[strlen(str[strtwo])][strlen(str[strone])] < 10){
                ans++;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
