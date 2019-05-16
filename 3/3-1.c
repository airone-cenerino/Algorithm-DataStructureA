# include<stdio.h>
# include <string.h>
# include <stdlib.h>

int main(int argc, char const *argv[])
{
    char str[256] = {};

    while(gets(str)!=NULL){
        char *tmp;
        char errmsg[256];
        char name;

        strcpy(errmsg, str);

        tmp = strtok(str, " ");
        name = *tmp;
        if(ch == 0){
            fprintf(stderr, "\n");
            continue;
        }

        int num = atoi(ch);
        ch = strtok(NULL, " ");

        if(ch == NULL){ //@1s‚É1•¶š‚µ‚©‚È‚©‚Á‚½‚Æ‚«(¬Œ÷)
            fprintf(stdout, "%d\n", num);
        }else{  // •¡”•¶š‚ª1s‚É‚ ‚Á‚½
            fprintf(stderr, "%s\n", errmsg);
        }
    }

    return 0;
}
