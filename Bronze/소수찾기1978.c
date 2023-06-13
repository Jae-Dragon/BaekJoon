#include <stdio.h>

int main()
{
    int N, count = 0, R;

    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &R);

        int g = 0;
        if(R == 1) continue;
        for(int j = 2; j < R; j++)
        {
            if(R % j == 0){
                g++;
                break;
            }
        }
        if(g == 0) count++;

    }
    printf("%d", count);

    return 0;
}