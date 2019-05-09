# include <stdio.h>

int main(int argc, char const *argv[])
{
    char moji;
    int num[26] = {0};

    while(scanf("%c", &moji)!=EOF){
        if('a'<=moji && moji <= 'z'){
            num[moji-'a'] ++;
        }
        if('A'<=moji && moji <= 'Z'){
            num[moji-'A'] ++;
        }
    }

    int max = 0;
    for(int i=0;i<26;i++){
        if(num[i]>max){
            max = num[i];
        }
    }

    printf("%d ", max);
    for(int j=0;j<26;j++){
        if(num[j] == max){
            printf("%c", 'a'+j);
        }
    }
    printf("\n");

    return 0;
}
