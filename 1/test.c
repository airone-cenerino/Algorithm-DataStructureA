#include <stdio.h>

int main(){
    int num =0;
    int i=0;
    int sum =0;
    
    while(scanf("%d", &num)==1){
        i++;
        sum+=num;
    }

	if (i == 0) {
		printf("No data\n");
	}
	else {
		printf("%d %d %.3f\n", i, sum, sum / (double)i);
	}

	return 0;
}