#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    while(1){
        int n, p, ans, i, max;
        scanf("%d", &n);
        scanf("%d", &p);

        if(n==0 && p==0)
            break;
        
        int *array;
        array = (int*)malloc(sizeof(int) * n);
        for(i=0;i<n;i++){
            array[i] = 0;
        }
        max = p;
        
        while(1){
            for(i=0;i<n;i++){
                // i番目の人のターン
                // 動作を書く

                // 石を1ことる
                if(p!=0){
                    p--;
                    array[i]++;
                }else{  // 椀に全部入れる
                    p = array[i];
                    array[i] = 0;
                }

                // ここで終了条件を満たしているか確認
                // 椀が空でiさんが全部持ってたら終わり
                if(p==0 && array[i] == max){
                    goto end;             
                }
            }
        }
        end:
            printf("%d\n", i);
    }
    return 0;
}
