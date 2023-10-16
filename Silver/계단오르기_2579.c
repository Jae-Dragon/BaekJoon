#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) a>b ? a:b

int main()
{
    /* 계단은 1, 2씩 오를 수 있음 */
    /* 연속된 3개의 계단을 모두 밟으면 안됨 */
    /* 마지막 계단은 반드시 밟아야 함 */
    /* DP, 동적계획법으로 해결해야 한다 */
    /* 가령 3번째 계단을 간다고 생각하면 가는 경우의 수는 0 -> 2 -> 3과 1 -> 3(맨 처음 2칸 전진)*/
    /* 4번 째 계단을 간다고 생각하면 1 -> 3 -> 4, 2 -> 4*/

    int N, stair[301], dp[301];

    scanf("%d", &N);

    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &stair[i]);
    }

    dp[0] = 0;
    dp[1] = stair[1];
    dp[2] = stair[1] + stair[2];

    for(int i = 3; i <= N; i++)
    {
        /* i로 가는 경우의 수는 2가지, i-2번째까지 더한 값에서 바로 점프해서 오는 것, i-3까지 더한 것에서 i전 칸까지 점프하고 i로 가는 것 */
        dp[i] = (MAX(dp[i-2], stair[i-1]+dp[i-3])) + stair[i];
    }
   
    printf("%d\n", dp[N]);


    return 0;
}