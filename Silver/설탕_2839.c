#include <stdio.h>

int main()
{
    int N, cnt3 = 0, cnt5 = 0, total = 0;
    scanf("%d", &N);

    /* 5만으로 표현 가능한 경우 굳이 3이 들어가는 조건을 계산할 필요가 없음 */
    if(N % 5 == 0){
            cnt5 = N / 5;
            printf("%d", cnt5);
            return 0;
    }

    /* 불가능 조건 체크 */
    int check = 0;
    /* 5의 최대 개수부터 최소 개수일 때 3이 몇개나 들어가는가 */
    for(int i = N / 5; i >= 0; i--)
    {
        cnt5 = i;
        if((N - 5 * i) % 3 == 0)
        {
            cnt3 = (N - 5 * i) / 3;
            check = 1;
            break;
        }
    }

    /* 3과 5만으로 구할 수 없는 경우 */
    if(check == 0 ){
        printf("-1");
        return 0;
    }

    total = cnt3 + cnt5;

    printf("%d", total);

    return 0;
}