# include<stdio.h>
# include <string.h>
# include <stdlib.h>

int distance(int tPos, int aPos, int gPos){
    int max = tPos;
    int min = tPos;

    if(max<aPos){
        max = aPos;
    }
    if(max<gPos){
        max = gPos;
    }

    if(min>aPos){
        min = aPos;
    }
    if(min>gPos){
        min = gPos;
    }

    return max - min;
}

int main(int argc, char const *argv[])
{
    int currentPosition = 0;
    char ch;
    int tPosition[25600] = {0};
    int aPosition[25600] = {0};
    int gPosition[25600] = {0};
    int tCount = 0;
    int aCount = 0;
    int gCount = 0;
    int ans=10000;

    while(scanf("%c", &ch)!=EOF){
        if(ch=='\n'){   // 改行は無視
            continue;
        }

        if(ch>= 'A' && ch<='Z'){
            ch += 'a'-'A';
        }

        switch (ch)
        {
        case 't':
            tPosition[tCount] =currentPosition;
            tCount++;
            break;
        case 'a':
            aPosition[aCount] =currentPosition;
            aCount++;
            break;
        case 'g':
            gPosition[gCount] =currentPosition;
            gCount++;
            break;
        }

        currentPosition++;
    }
    // ここまで入力------------------------------------------

    int t=0,a=0,g=0;        // 今何個目のtを見ているか
    int tPos = 0, aPos = 100000, gPos = 100000;   // 今見ているtの位置

    for(int i=0;i<currentPosition;i++){ // 前から順番に見ていく
        if(tPosition[t] == i){
            tPos = i;
            int dis = distance(tPos, aPos, gPos);
            if( dis < ans){
                ans = dis;
            }
            t++;
        }
        else if(aPosition[a] == i){
            aPos = i;
            int dis = distance(tPos, aPos, gPos);
            if( dis < ans){
                ans = dis;
            }
            a++;
        }
        else if(gPosition[g] == i){
            gPos = i;
            int dis = distance(tPos, aPos, gPos);
            if( dis < ans){
                ans = dis;
            }
            g++;    
        }
    }

    if(ans>=10000){
        printf("none\n");
    }else{
        printf("%d\n", ans);
    }

    return 0;
}
