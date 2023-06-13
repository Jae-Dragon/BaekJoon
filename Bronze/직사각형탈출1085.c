#include <stdio.h>
#include <math.h>

int main()
{
    int x, y;
    int w, h;

    scanf("%d %d %d %d", &x, &y, &w, &h); // 입력값

   int min = x;
    if (min > w - x)
        min = w - x;
    if (min > y)
        min = y;
    if (min > h - y)
        min = h - y;
    printf("%d\n", min);
    
    return 0;
}