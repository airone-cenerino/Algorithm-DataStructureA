# include<stdio.h>
# include <string.h>
# include <stdlib.h>

int main(int argc, char const *argv[])
{
    char str[256] = {};
    int kasidasiTime[26] = {};
    int ansMinutes = 0;

    while(gets(str)!=NULL){
        char *tmp;
        char name;
        char inOut;
        char *inOutTimeStr;
        int inoutTime;

        tmp = strtok(str, " ");
        name = *tmp;    // 船の名前をnameに格納
        tmp = strtok(NULL, " ");
        inOut = *tmp;   // InかOutかをinOutに格納
        tmp = strtok(NULL, " ");
        inOutTimeStr = tmp;    // 時間をinOutTimeStrに格納
        tmp = strtok(inOutTimeStr, ":");
        int hour = atoi(tmp);   // hourを取得
        tmp = strtok(NULL, ":");
        int minutes = atoi(tmp);   // minutesを取得

        if(inOut=='O'){ // 貸出
            kasidasiTime[name-'A'] = hour * 60 + minutes;
        }else{  // 返却
            ansMinutes += hour * 60 + minutes - kasidasiTime[name-'A'];
        }
    }

    printf("%d:%02d\n", ansMinutes/60, ansMinutes%60);

    return 0;
}
