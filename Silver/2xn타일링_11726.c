#include <stdio.h>

int main()
{
    /* 그냥 n을 1과 2로 채우는 경우의 수를 구하면 안되나 */

    int n, count = 0, ignite[1001];
    scanf("%d", &n);

    /* 점화식으로 해결하는 문제 */
    ignite[1] = 1; ignite[2] = 2;

    for(int i = 3; i <= n; i++)
    {
        ignite[i] = (ignite[i-1] + ignite[i-2]) % 10007;
    }

    printf("%d", ignite[n]);

    return 0;
}