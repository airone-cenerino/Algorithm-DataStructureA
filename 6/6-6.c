# include<stdio.h>
# include <string.h>
# include <stdlib.h>


// ベルマンフォード

int main(int argc, char const *argv[])
{
    int n,i,j, barNum=0;
    int start[100];
    int end[100];
    int distance[100];

    // 入力
    scanf("%d", &n);
    while(scanf("%d %d %d", &start[barNum], &end[barNum], &distance[barNum])!=EOF){
        barNum++;
    }

    // 0からの距離を格納する配列の初期化
    int array[n];
    array[0] = 0;
    for(int i=1;i<n;i++){
        array[i] = 100000;
    }

    int flg = 0;
    while(flg == 0){
        flg = 1;
        for(j=0;j<n;j++){
            //printf("j=%d\n", j);
            for(i=0;i<barNum;i++){
                if(start[i] == j){
                    //printf("%d %d\n", start[i], array[start[i]] + distance[i]);
                    if(array[end[i]] > array[start[i]] + distance[i]){  // すでに格納されている値よりも小さくできるなら
                        array[end[i]] = array[start[i]] + distance[i];
                        //printf("%d, dis=%d\n", end[i], array[end[i]]);
                        flg = 0;
                    }
                }

                if(end[i] == j){
                    if(array[start[i]] > array[end[i]] + distance[i]){  // すでに格納されている値よりも小さくできるなら
                        array[start[i]] = array[end[i]] + distance[i];
                        //printf("%d, dis=%d\n", start[i], array[start[i]]);
                        flg = 0;
                    }
                }

            }
        }
    }

    printf("%d\n", array[1]);
    
    
    return 0;
}
