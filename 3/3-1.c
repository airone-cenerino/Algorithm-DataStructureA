# include<stdio.h>
# include <string.h>
# include <stdlib.h>

int main(int argc, char const *argv[])
{
    char str[256] = {};

    while(gets(str)!=NULL){
        char *ch;
        char errmsg[256];

        strcpy(errmsg, str);

        ch = strtok(str, " ");
        if(ch == 0){
            fprintf(stderr, "\n");
            continue;
        }

        int num = atoi(ch);
        ch = strtok(NULL, " ");

        if(ch == NULL){ //�@1�s��1���������Ȃ������Ƃ�(����)
            fprintf(stdout, "%d\n", num);
        }else{  // ����������1�s�ɂ�������
            fprintf(stderr, "%s\n", errmsg);
        }
    }

    return 0;
}
