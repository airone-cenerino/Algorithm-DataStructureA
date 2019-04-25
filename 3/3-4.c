# include<stdio.h>

int main(int argc, char const *argv[])
{
    while(1){
        int a, b, price;
        scanf("%d %d %d", &a, &b, &price);

        if(a==0 && b==0 && price ==0)
            break;

        int moto = price / (1.0+a/100.0) + 2;   // Ø‚èÌ‚Ä+2‚©‚çl‚¦‚é

        int ans=0;
        int i;

        while(ans==0){
            for(i=1;i<moto/2+1;i++){    // moto‚ğ‚Q•ªŠ„‚·‚é
                double bairitu1 = 1.0 + a / 100.0;

                float num33 = (float)i*bairitu1;
                float num44 = (float)(moto-i)*bairitu1;

                int num3 = num33;
                int num4 = num44;

                if(num3 + num4 == price){
                    double bairitu2 = 1.0 + b / 100.0;

                    float num11 = (double)i * bairitu2;
                    float num22 = (double)(moto-i) * bairitu2;

                    int num1 = num11;
                    int num2 = num22;
                    if(ans < num1+num2){
                        ans = num1 + num2;
                    }
                }
            }

            moto--;
        }
        printf("%d\n", ans);
    }
    return 0;
}
