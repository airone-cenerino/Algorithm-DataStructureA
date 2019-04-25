# include<stdio.h>
# include<string.h>
# include<stdlib.h>

int main(int argc, char const *argv[])
{
    char name1[50] = {};
    char name2[50] = {};
    int min1 = 100000000;
    int min2 = 100000000;
    char str[256] = {};

    while(gets(str)!=NULL){
        char *name;
        char *numch;
        name = strtok(str, " ");
        numch = strtok(NULL, " ");

        int num = atoi(numch);

        if(min1>num){
            min2 = min1;
            strcpy(name2, name1);
            min1 = num;
            strcpy(name1, name);
        }else if(min2>num){
            min2 = num;
            strcpy(name2, name);
        }
    }

    printf("%s\n", name1);
    printf("%s\n", name2);
    
    return 0;
}
