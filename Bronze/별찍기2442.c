#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    for(int k = 0; k < N; k++)
    {
        for(int i = 0; i < N - k - 1; i++)
        {
            printf(" ");
        }
        for(int i = 1; i <= 2*k+1; i++)
        {
            printf("*");
        }
        printf("\n");

    }


    return 0;
}