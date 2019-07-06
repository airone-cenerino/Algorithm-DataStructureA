#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STACK_SIZE 1000
int stackNum = 0;
char stack[STACK_SIZE];

int pop(char *data)
{
    if (stackNum > 0) {
        stackNum--;
        *data = stack[stackNum];
        return 1;
    }else{
        return -1;
    }
}

int push(char data)
{
    stack[stackNum] = data;
    stackNum++;    
}

int main(int argc, char const *argv[])
{
    char c;
    while(1){
        int flg = 1;
        c=getchar();
        if(c=='.')
            break;

        if(c=='(' || c=='['){
            push(c);
        }else if(c==')' || c==']'){
            printf("no\n");
            // 途中で抜けているので残りの文字を消化しておく
            while(1){
                c = getchar();
                if(c=='.')
                    break;
            }

            continue;
        }

        while(1){
            c = getchar();
            if(c=='.')
                break;

            if(c=='(' || c=='['){
                push(c);
            }else if(c==')' || c==']'){
                char tmp;
                if(pop(&tmp)==-1){
                    printf("no\n");
                    flg = 0;
                    break;
                }

                if(!((tmp=='(' && c==')') || tmp=='[' && c==']')){
                    printf("no\n");
                    flg = 0;
                    break;
                }
            }
        }

        if(flg){
            if(stackNum == 0){
                printf("yes\n");
            }else{
                printf("no\n");
            }
        }else{
            // 途中で抜けているので残りの文字を消化しておく
            while(1){
                c = getchar();
                if(c=='.')
                    break;
            }
        }

        // ここでスタックの初期化
        stackNum = 0;
        c=getchar();// 改行コードの取り出し
    }

    return 0;
}
