#include <stdio.h>
#include <stdlib.h>

void printArray(int** array, int h){
    int i, j;
    for(i=h-1;i>=0;i--){
        for(j=0;j<5;j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    while(1){
        int h, i, j, ans = 0;
        scanf("%d", &h);

        if(h==0) break;

        int **array;
        array = (int**)malloc(sizeof(int*) * h);
        for(i=0;i<h;i++){
            array[i] = (int*)malloc(sizeof(int) * 5);
        }

        for(i=h-1;i>=0;i--){    // 数字が小さいほど下
            scanf("%d %d %d %d %d", &array[i][0], &array[i][1], &array[i][2], &array[i][3], &array[i][4]);
        }

        //printArray(array, h);


        // ここから連鎖が止まるまでループ
        int last = 0;
        int now, k;
        int ren = 1;
        int flg = 0;

        while(1){
            flg = 0;
            for(i=0;i<h;i++){
                for(j=0;j<5;j++){
                    if(last == array[i][j] && last!=-1 && !j==0){
                        ren++;
                    }else{
                        if(ren>=3){
                            //printf("point=%d\n", ans);

                            ans += last * ren;  // 得点が入る
                            printf("last=%d", last);
                            printf("ren=%d\n", ren);
                            printf("point=%d\n", ans);

                            // ここで消す(-1を入れる)
                            if(j!=0){// i列に消す対象がいる
                                //array[i][j-1]から前ren個
                                for(k=0;k<ren;k++){
                                    array[i][j-1-k] = -1;
                                }
                            }else{  // i-1列に消す対象がいる
                                //array[i-1][4]から前ren個
                                for(k=0;k<ren;k++){
                                    array[i-1][4-k] = -1;
                                }
                            }

                            flg = 1;
                        }
                        ren = 1;
                    }

                    last = array[i][j];
                }

                if(ren<3){
                    ren = 0;
                }
            }

            if(ren>=3){ // 最後に消える部分があった時はここで処理する
                ans += last * ren;  // ここで消えて得点が入る
                for(k=0;k<ren;k++){
                    array[h-1][4-k] = -1;
                }
                flg = 1;
                ren = 1;
            }

            printArray(array, h);

            

            // ここに落ちる部分を書く
            for(i=0;i<h;i++){
                for(j=0;j<5;j++){
                    // 順番にみて、-1があったら上を見ておろしてくる
                    if(array[i][j] == -1){
                        // 上を見ていく
                        int up = 1;
                        while(i+up<h){
                            // -1以外があったら入れ替え
                            if(array[i+up][j] != -1){
                                array[i][j] = array[i+up][j];
                                array[i+up][j] = -1;
                                break;
                            }
                            up++;
                        }
                    }
                }
            }

            printArray(array, h);

            if(flg == 0) break;
        }

        printf("%d\n", ans);
    }

    return 0;
}