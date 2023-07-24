#include <stdio.h>

int main()
{
    int N, k = 0, t = 666;
    scanf("%d", &N);

    while (k < N)//원하는 666이 들어간 N번째 숫자를 구할 때 까지 실행
    {
        int temp = t, check = 0; // 666이 들어가있는지 체크

        /* 아마도 케이스를 좀 나눠야 하지 않을까 */
        /* 6의 개수를 세고 만약 6이 4개 이상이면 +1을 해주고 아니면 1000을 더해준다? */
        //->기각

        /* 666이 들어가는 수를 차례로 구하여 그것이 N에 도달할 떄까지 실행 */

        while(temp)
        {
            if (temp % 1000 == 666)
            {
                check = 1;
            }
            temp /= 10;
        }

        if (check)//666이 있다면 
        {
            k++;
        }
        t++;//다음 숫자로 이동 ex) 666 -> 667 -> 668 ... 1666 -> 1667 ...
    }

    printf("%d", t-1);//맨 마지막 실행 때 한번 더 더해지므로 1을 뺴줘야함

    return 0;
}