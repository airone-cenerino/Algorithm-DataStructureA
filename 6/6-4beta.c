# include<stdio.h>
# include <string.h>
# include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n, syou = 1, amari = 1;
    int syouArr[100];
    int amariArr[100];
    scanf("%d", &n);

    int i, j, k, flg=0;
    for(i=0;i<100;i++){
        amari *= 10;
        syou = amari/n;
        amari = amari % n;
        syouArr[i] = syou;
        amariArr[i] = amari;

        if(amari == 0)
            break;

        for(j=0;j<i;j++){
            if(amariArr[j]==amari){
                flg = 1;    // 循環小数のフラグ
                if(syouArr[j]==syouArr[i]){
                    i--;
                    j--;
                }
                break;
            }
        }

        if(flg) break;
    }

    printf("0.");

    for(k=0;k<=i;k++){
        if(k==j+1 && flg)
            printf("'");
        printf("%d", syouArr[k]);
    }

    printf("\n");

    return 0;
}
