#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    while(1){
        int h, w;
        scanf("%d %d", &h, &w);
        if(h==0 && w==0)
            break;
        
        int taikaku = h * h + w * w;

        // 全探索して自分より大きい最小が来るたび更新する。
        int width;
        int ansW;
        int ansH;
        int min = 100000;   // これまでで一番短かった対角線
        int minHeight = 1000;
        int flg = 0;
        for(width=2;width<=150;width++){
            int height;
            for(height=1;height<width;height++){
                int newTaikaku = width*width + height * height;

                if(taikaku == newTaikaku && h < height){
                    min = newTaikaku;
                    minHeight = height;
                    ansW = width;
                    ansH = height;
                    flg ==1;
                }
                else if(taikaku < newTaikaku && min >= newTaikaku){
                    if(minHeight > height || min > newTaikaku){
                        min = newTaikaku;
                        minHeight = height;
                        ansW = width;
                        ansH = height;
                    }
                }
            }
        }

        printf("%d %d\n", ansH, ansW);
    }

    return 0;
}