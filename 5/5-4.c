# include<stdio.h>
# include <string.h>
# include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);

    for(int i=0;i<n;i++){
        int year, month, day;
        int ans=0;
        scanf("%d %d %d", &year, &month, &day);


        for(int y=year;y<1000;y++){
            int tmp = 1;
            if(y == year){
                tmp = month;
            }

            for(int m=tmp;m<=10;m++){
                if(y==year&&m==month){
                    if(m%2==0){
                        if(y%3==0){
                            ans += 20-day;
                        }else{
                            ans += 19-day;
                        }
                    }else{
                        ans += 20-day;
                    }
                    continue;
                }

                if(m%2==0){
                    if(y%3==0){
                        ans += 20;
                    }else{
                        ans += 19;
                    }
                }else{
                    ans += 20;
                }
            }
        }

        printf("%d\n", ans+1);
    }

    return 0;
}
