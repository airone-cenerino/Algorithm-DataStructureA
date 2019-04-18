#include <stdio.h>
#include <string.h>
#include <float.h>

int main(int argc, char const *argv[])
{
    char ans[500];
    double minweight = DBL_MAX;

    while(1){
        char name[500];
        double height;
        double weight;

        if(scanf("%s %lf %lf", name, &height, &weight) == EOF) break;
        if(weight/(height*height) <= minweight){
            strcpy(ans, name);
            minweight = weight/(height*height);
        }
    }

    printf("%s\n", ans);

    return 0;
}
