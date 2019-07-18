# include<stdio.h>
# include <string.h>
# include <stdlib.h>

void printBars(int **bars, int n){
    int i, j;
    for(i=0;i<3;i++){
        for(j=0;j<n;j++){
            if(bars[i][j]==-1){
                printf(".");
            }else{
                printf("%d", bars[i][j]);
            }
        }
        if(i!=2)
            printf(" ");
    }
    printf("\n");
}

void barChange(int **bars, int from, int to, int n){
    int num;
    int i;

    for(i=0;i<n;i++){
        if(bars[from][i] != -1){
            num = bars[from][i];
            bars[from][i] = -1;
            break;
        }
    }

    for(i=n-1;i>=0;i--){
        if(bars[to][i] == -1){
            bars[to][i] = num;
            break;
        }
    }
}

void move(int n, int a, int b, int c, int **bars, int maxN){
    if(n==1){
        barChange(bars, a, c, maxN);
        printBars(bars, maxN);
    }else{
        move(n-1, a, c, b, bars, maxN);
        barChange(bars, a, c, maxN);
        printBars(bars, maxN);
        move(n-1, b, a, c, bars, maxN);
    }
}

int main(int argc, char const *argv[])
{
    int n, i, j;
    scanf("%d", &n);

    int **bars;
    bars = (int**)malloc(sizeof(int*)*3);
    for(i=0;i<3;i++){
        bars[i] = (int*)malloc(sizeof(int)*n);
    }

    for(j=0;j<3;j++){       
        for(i=0;i<n;i++){
            if(j==0){
                bars[j][i] = i;
            }else{
                bars[j][i] = -1;
            }
        }
    }
    printBars(bars, n);
    move(n, 0, 1, 2, bars, n);
    
    for(i=0;i<3;i++){
        free(bars[i]);
    }
    free(bars);

    return 0;
}
