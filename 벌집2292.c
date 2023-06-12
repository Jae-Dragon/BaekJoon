#include <stdio.h>

int main()
{
    /* 등비급수 문제가 아닐까 */
    /* 아마도 곱하는 수가 6씩 계속 더해지면서 가는 것이 규칙 같기는 한디 */
    /* 우선 N을 찾고 싶은 방 */
    int N;
    scanf("%d", &N);
    /* K를 늘어나는 비율?(6)*/
    int k = 1, count = 1;

    while(k < N && N != 1){
        k += 6*count;
        count++;
    }
    printf("%d",count);



    return 0;
}