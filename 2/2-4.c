#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int n;
    int i;
    scanf("%d", &n);
    char str[100] = "9";
    char last[100] = "9";


    while(strlen(str)<n+1){
        int kuriagari = 0;
        strcpy(last, str);
        char newStr[100] = {0};

        // str‚ðˆêŒ…‚¸‚ÂŽæ‚èo‚µ‚Ä3‚ð‚©‚¯‚Ästr‚É–ß‚·B
        for(i=0;i<strlen(str);i++){
            int num = str[i]-'0';
            num *= 3;
            num += kuriagari;

            newStr[i] = num%10 + '0';
            kuriagari = num/10;
        }
        if(kuriagari!=0)
            newStr[i] = kuriagari + '0';

        strcpy(str, newStr);
    }

    char ans[100];

    for(i=0;i<strlen(last);i++){
        ans[i] = last[strlen(last)-i-1];
    }
    ans[i] = '\0';

    printf("%s\n", ans);

    return 0;
}
