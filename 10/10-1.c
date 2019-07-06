#include<stdio.h>
#include<stdlib.h>

int ans = 0;

void BreakIce(int **array, int x, int y, int depth){
    array[y][x] = 0;
    //printf("depth=%d\n", depth+1);

    // 氷があれば進む
    if(array[y-1][x] == 1){
        // printf("上");
        BreakIce(array, x, y-1, depth+1);
    }
    if(array[y+1][x] == 1){
        // printf("下");
        BreakIce(array, x, y+1, depth+1);
    }
    if(array[y][x-1] == 1){
        // printf("左");
        BreakIce(array, x-1, y, depth+1);
    }
    if(array[y][x+1] == 1){
        // printf("右");
        BreakIce(array, x+1, y, depth+1);
    }

    array[y][x] = 1;

    // 行き止まりで終わり
    if(array[y-1][x] == 0 && array[y+1][x] == 0 && array[y][x-1] == 0 && array[y][x+1] == 0){
          //printf("行き止まり\n");
        
        if(ans<depth+1){
            ans = depth+1;
            // printf("%d\n", depth+1);
        }
    }
}

int main(int argc, char const *argv[])
{
    int h, w, i, j;
    scanf("%d", &w);
    scanf("%d", &h);

    int **array;
    array = (int**)malloc(sizeof(int*) * (h+2));
    for(i=0;i<h+2;i++){
        array[i] = (int*)malloc(sizeof(int) * (w+2));
    }

    for(int i=0;i<h+2;i++){
        for(int j=0;j<w+2;j++){
            if(i>0 && i<=h && j>0 && j<=w){
                scanf("%d", &array[i][j]);
            }else{
                array[i][j] = 0;
            }
        }
    }

    // 割り始める場所
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(array[i][j]==1){
                // printf("(%d,%d)\n", j, i); 
                BreakIce(array, j, i, 0);
                // printf("\n");
                // printf("\n");
                // printf("\n");
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
