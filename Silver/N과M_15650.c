#include <stdio.h>

void search(int *arr, int count, int last, int N, int M);

int main()
{
    int N, M, arr[9] = {
                  0,
              };
    scanf("%d %d", &N, &M);

    search(arr, 1, 1, N, M);

    return 0;
}

void search(int *arr, int count, int last, int N, int M)
{
    /* count를 바구니의 번호, last를 바구니에 넣는 공의 개수라고 생각해보자 */
    /* N은 공의 최대 개수, M은 바구니의 개수이다. */
    /* last는 바로 앞 방보다 무조건 커야 하기에 재귀호출을 할 때 +1을 하여 호출한다. */

    /* 여기에서는 arr[0]은 사용하지 않고 arr[1]부터 사용했기 때문에 마감 조건에 1을 더해줘야 한다 */
    if (M + 1 == count)
    {
        for (int i = 1; i <= M; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else
    {
        for (int i = last; i <= N; i++)
        {
            /* 1번 방에는 기준이 되는 가장 작은 수, 그 다음 방에는 last보다는 큰 수들이 와야 하기 때문에 */
            arr[count] = i;
            search(arr, count + 1, i + 1, N, M);
        }
    }
}