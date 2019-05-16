# include<stdio.h>
# include <string.h>
# include <stdlib.h>

int cmp1( const void * a , const void * b ) {
    if( *( char * )a < *( char * )b ) {
        return -1;
    }
    else
        if( *( char * )a == *( char * )b ) {
        return 0;
        }
    return 1;
}

int cmp2( const void * a , const void * b ) {
    if( *( char * )a < *( char * )b ) {
        return 1;
    }
    else
        if( *( char * )a == *( char * )b ) {
        return 0;
        }
    return -1;
}

int main(int argc, char const *argv[])
{
    int a0;
    int L;

    loop:
        scanf("%d %d", &a0, &L);
        if(a0==0 && L==0) return 0;

        int rireki[20];
        rireki[0] = a0;
        int count = 1;
        char str[L];    // 数字を入れる配列


        while(1){
            if(count == 1){
                sprintf(str, "%d", a0);
            }else{
                sprintf(str, "%d", rireki[count-1]);
            }

            //0埋め----------------  
            int mojisuu;
            for(mojisuu=0; str[mojisuu]!='\0'; ++mojisuu);    // 文字数取得

            for(int i=0;i<L-mojisuu;i++){
            str[mojisuu+i] = '0';
            }
            //0埋めここまで----------------

            qsort(str, L, sizeof(char), cmp1);
            int smallestNum = atoi(str);

            qsort(str, L, sizeof(char), cmp2);
            int biggestNum = atoi(str);

            rireki[count] = biggestNum-smallestNum;

            // ここで同じ値が過去にあったか確認しろ。
            for(int i=0;i<count;i++){
                if(rireki[i] == rireki[count]){
                    printf("%d %d %d\n", i, rireki[i], count-i);
                    goto loop;
                }
            }

            count++;
        }
    
    
    return 0;
}
