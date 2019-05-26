# include<stdio.h>
# include <string.h>
# include <stdlib.h>

int main(int argc, char const *argv[])
{
    char str1[256];
    char str2[256];

    scanf("%s", str1);
    scanf("%s", str2);

    // dpのメモリ確保
    int **dp;
    dp = (int**)malloc(sizeof(int*) * (strlen(str2) + 2));
    int i, j;
    for(i=0;i<strlen(str2)+1;i++){
        dp[i] = (int*)malloc(sizeof(int) * (strlen(str1) + 2));
    }


    // dp初期化
    for(i=0;i<strlen(str2)+1;i++){
        dp[i][0] = i;
    }
    for(i=0;i<strlen(str1)+1;i++){
        dp[0][i] = i;
    }

    for(i=1;i<strlen(str2)+1;i++){
        for(j=1;j<strlen(str1)+1;j++){
            int min = 1000;
            if(min > dp[i-1][j]+1) min = dp[i-1][j]+1;
            if(min > dp[i][j-1]+1) min = dp[i][j-1]+1;

            if(str2[i-1]==str1[j-1]){
                if(min > dp[i-1][j-1]) min = dp[i-1][j-1];
            }else{
                if(min > dp[i-1][j-1]+1) min = dp[i-1][j-1]+1;                
            }

            dp[i][j] = min;
        }
    }


    printf("%d\n", dp[strlen(str2)][strlen(str1)]);

    
    return 0;
}
