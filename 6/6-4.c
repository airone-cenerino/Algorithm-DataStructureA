# include<stdio.h>
# include <string.h>
# include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n, syou = 1, amari = 1;
    int syouArr[100];
    int amariArr[100];
    scanf("%d", &n);

    int i, j, flg=0;
    for(i=0;i<100;i++){
        amari *= 10;
        syou = amari/n;
        amari = amari % n;
        syouArr[i] = syou;
        amariArr[i] = amari;
        printf("%d %d\n", syou, amari);

        if(amari == 0)
            break;
        
        for(j=0;j<i;j++){
            if(amariArr[j]==amari){
                printf("owari\n");
                flg = 1;
                break;
            }
        }

        if(flg) break;
    }
    return 0;
}
