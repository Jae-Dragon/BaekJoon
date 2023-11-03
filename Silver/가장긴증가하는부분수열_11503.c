#include <stdio.h>
#define MAX(A,B) A > B ? A : B
int main()
{
    int arr[1001], LIS[1001], N, count = 0;
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    //LIS[i]: A[i]를 포함하는 가장 긴 부분 수열의 길이
    LIS[0] = 1;

    /* i가 기준이 되고 */
    for(int i = 1; i < N; i++)
    {
        LIS[i] = 1;

        /* A[i]전까지 있는 부분 수열들을 돌면서 만약 A[i]가 앞에 있는 수보다 크다면 그것의 수열에 +1하는 것이 A[i]의 가장 긴 수열이 된다. */
        for(int j = 0; j < i; j++)
        {
            if(arr[i] > arr[j])
            {
                LIS[i] = MAX(LIS[i], LIS[j]+1);
            }
        }
    }

    int max = 0;
    /* LIS[N-1]이 가장 긴 수열이 아닐 수 있기 때문에 LIS 전체를 검사 */
    for(int i = 0; i < N; i++)
    {
        if(LIS[i] > max)
            max = LIS[i];
    }

    printf("%d\n", max);

   


    return 0;
}