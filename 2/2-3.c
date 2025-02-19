#include <stdio.h>
#include <string.h>
#include <ctype.h>

void trim( char *s ) {
    int i, j;
 
    //文字列の最後から空白を読み飛ばして除外する
    for( i = strlen(s)-1; i >= 0 && isspace( s[i] ); i-- ) ;
    s[i+1] = '\0';
    //先頭から空白でない文字まで読み飛ばす
    for( i = 0; isspace( s[i] ); i++ ) ;
    //前方の空白を詰める
    if( i > 0 ) {
        j = 0;
        while( s[i] ) s[j++] = s[i++];
        s[j] = '\0';
    }
}

int main(int argc, char const *argv[])
{
    char str[100] = {0};
    char minStr[100] = "zzzzzz";

    while(scanf("%s", str)!=EOF){
        int i=0;
        while(1){
            // 大文字を小文字に直せ
            if(str[i]<'a'){
                str[i] = str[i]-'A'+'a';
            }


            if(minStr[i] > str[i]){
                strcpy(minStr, str);
                break;
            }else if(minStr[i] != str[i]){
                break;
            }
            i++;
        }
    }

    trim(minStr);
    printf("%s", minStr);
    return 0;
}