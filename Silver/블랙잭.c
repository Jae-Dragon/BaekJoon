#include <stdio.h>
#include<stdlib.h>

int main()
{
    int N, M, *ARR;
    scanf("%d %d", &N, &M);

    ARR = (int*)malloc(sizeof(int)*N);

    if(ARR == NULL) return -1;

    for(int i = 0; i < N; i++)
    {
        scanf("%d", ARR+i);
    }

    int max = 0;
    int g = 0;
    
    for(int i = 0; i < N; i++)
    {
        for(int j = i+1; j < N; j++)
        {
            for(int k = j+1; k < N; k++)
            {
                g = 0;
                g = *(ARR+i) + *(ARR+j) + *(ARR+k);
              
                if(g > max && g <= M) max = g;
            }
        }
    }

    printf("%d", max);

    free(ARR);

    return 0;
}