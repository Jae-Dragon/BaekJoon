#include <stdio.h>
#include <limits.h>
#define MAX(a,b) a > b ? a : b

int main()
{
    int N, arr[100001], dp[100001];
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    /* 기준으로 잡은 값 vs 기준값 전까지의 수열 중에서 최댓값 + 기준값 */

    dp[0] = arr[0];

    for(int i = 1; i < N; i++)
    {       
        dp[i] = MAX(arr[i], arr[i]+dp[i-1]);       
    }

    int max = INT_MIN;
    for(int i = 0; i < N; i++)
    {
        max = MAX(dp[i], max);
    }

    printf("%d\n", max);

    return 0;
}