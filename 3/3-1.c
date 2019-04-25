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

        if(ch == NULL){ //@1s‚É1•¶š‚µ‚©‚È‚©‚Á‚½‚Æ‚«(¬Œ÷)
            fprintf(stdout, "%d\n", num);
        }else{  // •¡”•¶š‚ª1s‚É‚ ‚Á‚½
            fprintf(stderr, "%s\n", errmsg);
        }
    }

    return 0;
}
