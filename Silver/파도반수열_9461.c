#include <stdio.h>

int main()
{
    int N, T;

    long long arr[101];

    arr[1] = 1; arr[2] = 1; arr[3] = 1; arr[4] = 2; arr[5] = 2; 
    arr[6] = 3; arr[7] = 4; arr[8] = 5; arr[9] = 7; arr[10] = 9;

    arr[11] = 12;//3 + 9
    arr[12] = 16;//4 + 12

    for(int i = 11; i <= 100; i++)
    {
        arr[i] = arr[i-1] + arr[i-5];
    }
   

    scanf("%d", &T);

    for(int i = 0; i < T; i++)
    {
        scanf("%d", &N);
        printf("%lld\n", arr[N]);

    }


    return 0;
}