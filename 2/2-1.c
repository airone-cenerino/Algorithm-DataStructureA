#include <stdio.h>

int main(int argc, char const *argv[])
{
    int list[26];
    for(int i=0;i<26;i++){
        list[i] = 0;
    }

    while(1){
        char ch;
        if(scanf("%c", &ch) == EOF)
            break;
        
        if(ch>='a' && ch<='z'){
            list[ch-'a']++;
        }else if(ch>='A' && ch<='Z'){
            list[ch-'A']++;
        }
    }

    for(int i=0;i<26;i++){
        if(list[i]==0){
            printf("%c", i+'a');
        }
    }
    printf("\n");

    return 0;
}
