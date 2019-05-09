#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int x[4];
    int y[4];
    int i;
    for(int i=0;i<4;i++){
        scanf("%d %d", &x[i], &y[i]);
    }

    double a = sqrtl((x[0]-x[1]) * (x[0]-x[1]) + (y[0]-y[1]) * (y[0]-y[1]));
    double b = sqrtl((x[0]-x[2]) * (x[0]-x[2]) + (y[0]-y[2]) * (y[0]-y[2]));
    double c = sqrtl((x[1]-x[2]) * (x[1]-x[2]) + (y[1]-y[2]) * (y[1]-y[2]));

    double d = sqrtl((x[0]-x[3]) * (x[0]-x[3]) + (y[0]-y[3]) * (y[0]-y[3]));
    double e = sqrtl((x[3]-x[2]) * (x[3]-x[2]) + (y[3]-y[2]) * (y[3]-y[2]));
    double f = sqrtl((x[0]-x[2]) * (x[0]-x[2]) + (y[0]-y[2]) * (y[0]-y[2]));


    double menseki1 = a* b/2 * sqrt(1-((a*a+b*b-c*c)/2/a/b) * ((a*a+b*b-c*c)/2/a/b));
    double menseki2 = d* e/2 * sqrt(1-((d*d+e*e-f*f)/2/d/e) * ((d*d+e*e-f*f)/2/d/e));

    printf("%.3f\n", menseki1+menseki2);


    return 0;
}
