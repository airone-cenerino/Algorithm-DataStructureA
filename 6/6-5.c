# include<stdio.h>
# include <string.h>
# include <stdlib.h>

int main(int argc, char const *argv[])
{
    int arr[10000];
    int i,j, kyori, rightFlg=1, leftFlg=1;
    int max = 0, yokoLen, ans = 0;

    while(scanf("%d", &arr[i]) != EOF){
        i++;
    }

    for(j=0;j<i;j++){
        kyori=1;
        yokoLen=1;
        rightFlg=1;
        leftFlg=1;
        int height = arr[j];

        while(1){
            if(rightFlg){
                if(j-kyori>=0){
                    if(height<=arr[j-kyori]){
                        yokoLen++;
                    }else{
                        rightFlg=0;
                    }
                }else{
                    rightFlg=0;
                }
            }

            if(leftFlg){
                if(j+kyori<i){
                    if(height<=arr[j+kyori]){
                        yokoLen++;
                    }else{
                        leftFlg=0;
                    } 
                }else{
                    leftFlg=0;
                }
            }

            if(rightFlg==0&& leftFlg==0){
                break;
            }
            kyori++;
        }

        if(yokoLen*height>ans){
            ans = yokoLen * height;
        }
    }

    printf("%d\n", ans);
    
    return 0;
}
