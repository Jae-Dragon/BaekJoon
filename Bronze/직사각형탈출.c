#include <stdio.h>
#include <math.h>

int main()
{
    int x, y;
    int w, h;

    scanf("%d %d %d %d", &x, &y, &w, &h);//입력값
    
    /* 효율적인 해결방법을 생각해보자 */
    /* 중점을 파악하고 그것을 기준으로 사분면을 나누어 가장 가까운 꼭짓점을 찾자 */

    int d;//4개의 꼭짓점으로부터의 거리

    float c1, c2;//중점의 x, y
    c1 = x/2; c2 = y/2;//중점

    if(x > c1 && y > c2){//1사분면일 때는 맨 오른쪽 상단 (w, h)
        d = sqrt((w - x) * (w - x) + (h - y) * (h - y));
    }
    else if(x < c1 && y > c2){//2사분면일 때는 맨 왼쪽 상단 (0,h)
        d = sqrt((x) * (x) + (h - y) * (h - y));
    }
    else if(x < c1 && y > c2){//3사분면일 때는 맨 왼쪽 하단 (0,0)
        d = sqrt((x) * (x) + (y) * (y));
    }
     else if(x < c1 && y > c2){//4사분면일 때는 맨 오른쪽 하단 (w,0)
        d = sqrt((w - x) * (w - x) + (y) * (y));
    }
    
    printf("%d", d);


    return 0;
}