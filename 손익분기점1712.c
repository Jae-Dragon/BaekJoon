#include <stdio.h>

int main()
{
    int A, B, C, N;

    scanf("%d %d %d", &A, &B, &C);
    /* A 고정비용, B 고정비용, C 가격 */
    /* A + B * N < C * N을 구해야 한다 */
    /* C*N - B*N > A */
    /* N > A/(C-B) */

    //통과가 안되는 케이스를 찾아야 하는데 우선 고정 비용이 가격보다 높은 경우

    if(B >= C){
        printf("-1");
        return 0;
    }
    N = A/(C-B) + 1;

    printf("%d", N);

    return 0;
}