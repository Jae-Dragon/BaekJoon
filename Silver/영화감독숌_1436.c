#include <stdio.h>

int main()
{
    int N, k = 0, t = 666;
    scanf("%d", &N);

    while (k < N)
    {
        int temp = t, check = 0; // 6의 개수를 저장
        /* 아마도 케이스를 좀 나눠야 하지 않을까 */
        /* 6의 개수를 세고 만약 6이 4개 이상이면 +1을 해주고 아니면 1000을 더해준다? */

        while (temp)
        {
            if (temp % 1000 == 666)
            {
                check = 1;
            }
            temp /= 10;
        }

        if (check)
        {
            k++;
         
        }
     
        t++;
    }

    printf("%d", t-1);

    return 0;
}