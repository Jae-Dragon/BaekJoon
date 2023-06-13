#include <stdio.h>

int main()
{
    int N, A, I;
    scanf("%d %d", &A, &I);
    /* N/A == I가 나와야 한다. */
    /* 우리가 구해야 하는 것이 N이므로 A*I를 해야하는데 N/A를 할 때 항상 올림이므로 올림을 해서 나올 수 있는 최솟값을 구해야함 */
    //그럼 N의 최댓값은 A*I이므로 거기서 A를 빼면서 최솟값을 구해야 한다

    int max = 0;
    max = A*I;//N의 최댓값
    
    for(int i = A-1; i >=1; i--)
    {
        max--;
    }

    printf("%d", max);

    return 0;
}