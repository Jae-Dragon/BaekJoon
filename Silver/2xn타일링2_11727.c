#include <stdio.h>

int main()
{
    int N;
    scanf("%d",&N);

    int dp[1001];

    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 5;
    dp[4] = 11;
    dp[5] = 21;

    for(int i = 3; i <= N; i++)
    {
        dp[i] = (dp[i-2]*2 + dp[i-1]) % 10007;
    }

    printf("%d", dp[N]);

    return 0;
}