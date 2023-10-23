#include <stdio.h>

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    int arr[100001] = {0,}, sum[100001] ={0,};

    for(int g = 1; g <= N; g++)
    {
        scanf("%d", &arr[g]);
        sum[g] = sum[g-1] + arr[g];
    }

    int i, j;

    for(int g = 1; g <= M; g++)
    {
        scanf("%d %d", &i, &j);
        int SUM = sum[j] - sum[i-1];
        printf("%d\n", SUM);        
    }



    return 0;
}