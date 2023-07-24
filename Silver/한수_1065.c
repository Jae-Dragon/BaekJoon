#include <stdio.h>

int main()
{
    int N, count = 0;
    scanf("%d", &N);

    /* 이러면 한자리 수랑 두자리 수는 무조건 한수아님? */

    for(int i = 1; i <= N; i++)
    {
        /* 이러면 한자리 수랑 두자리 수일 때 */
        if(i / 100 == 0)
        {
            count++;
            continue;
        }

        /* 1000미만의 수들이 남았고 그것들은 전부 세자리 수이므로 */
        int g1 = i % 10;
        int g2 = (i / 10) % 10;
        int g3 = (i / 100);
        if(g2 - g1 == g3 - g2) count++;

    }


    printf("%d", count);

    return 0;
}