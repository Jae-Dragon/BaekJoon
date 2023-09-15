#include <stdio.h>

int main()
{
    int N, K, arr[10];
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    int location = 0;

    while (location < N)
    {
        if (arr[location] == K)
        {
            break;
        }
        else if (arr[location] > K)
        {
            location--;
            break;
        }

        if(location >= N-1) break;

        location++;
    }

    int count = 0, g = 0;

    while (K > 0)
    {
        if (arr[location] <= K)
        {
            g = K / arr[location];
            count += g;
            K -= g * arr[location];
        }

        location--;
    }

    printf("%d", count);

    return 0;
}