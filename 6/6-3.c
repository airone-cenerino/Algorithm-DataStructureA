# include<stdio.h>
# include <string.h>
# include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n, taisyou, houkou, i;
    while(1){
        scanf("%d", &n);
        if(n==0) return 0;

        int **arr;      //[ﾂ架敖氾板姪堋て堋税つ頁ｱﾂ形][xﾂ最板標ﾂて?yﾂ最板標]
        arr = (int**)malloc(sizeof(int*)*n);
        for(i=0;i<n;i++){
            arr[i] = (int*)malloc(sizeof(int)*2);
        }

        arr[0][0] = 0;
        arr[0][1] = 0;

        for(i=1;i<n;i++){
            scanf("%d %d", &taisyou, &houkou);

            switch(houkou){
                case 0: // ﾂ最?
                    arr[i][0] = arr[taisyou][0]-1;
                    arr[i][1] = arr[taisyou][1];
                    break;
                case 1: // ﾂ嫁?
                    arr[i][0] = arr[taisyou][0];
                    arr[i][1] = arr[taisyou][1]-1;
                    break;
                case 2: // ﾂ右 
                    arr[i][0] = arr[taisyou][0]+1;
                    arr[i][1] = arr[taisyou][1];  
                    break;
                case 3: // ﾂ焼?
                    arr[i][0] = arr[taisyou][0];
                    arr[i][1] = arr[taisyou][1]+1;
                    break;
            }            
        }

        int maxX=-1000, maxY=-1000, minX=1000, minY=1000;
        // ﾂ全ﾂ探ﾂ最?
        for(i=0;i<n;i++){
            if(maxX<arr[i][0]){
                maxX = arr[i][0];
            }
            if(maxY<arr[i][1]){
                maxY = arr[i][1];
            }            
            if(minX>arr[i][0]){
                minX = arr[i][0];
            }                 if(minY>arr[i][1]){
                minY = arr[i][1];
            } 
        }

        printf("%d %d\n", (maxX-minX)+1, (maxY-minY)+1);
    }
    
    return 0;
}
