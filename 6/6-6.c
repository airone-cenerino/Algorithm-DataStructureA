# include<stdio.h>
# include <string.h>
# include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n, i=0, ans=0;
    int start[100];
    int end[100];
    int distance[100];
    int cost[100];
    int currentLookingPoint[100];
    int currentLookingPointNum = 1;
    scanf("%d", &n);
    

    while(scanf("%d %d %d", &start[i], &end[i], &distance[i])!=EOF){
        i++;

        // startとendを逆にして入れる
        start[i] = end[i-1];
        end[i] = start[i-1];
        distance[i] = distance[i-1];

        i++;
    }

    currentLookingPoint[0] = 0
    currentLookingPointNum = 1;
    
    while(1){

    }
    
    return 0;
}
