#include <stdio.h>

int main(int argc, char const *argv[])
{
    int ans = 0;
    int flg = 0;


    while(1){
        char ch;

        if(scanf("%c", &ch) == EOF)
            break;

        if(flg==0){
            if(ch=='/'){
                flg=1;
            }
        }else if(flg==1){
            if(ch=='*'){
                flg=2;
            }else if(ch=='/'){
                flg=1;
            }else{
                flg=0;
            }
        }else if(flg==2){
            if(ch=='*'){
                flg=3;
            }
        }else{
            if(ch=='/'){
                flg=0;
                ans++;
            }else if(ch=='*'){
                flg=3;
            }else{
                flg=2;
            }
        }
    }

    printf("%d\n", ans);


    return 0;
}
