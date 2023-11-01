#include <stdio.h>
#include <stdlib.h>

int N, M;
int arr[9];
int print_arr[9];

int compare(const void *a, const void *b)
{
    int A = *(int *)a;
    int B = *(int *)b;

    if (A > B)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void search(int count)
{
    if (count == M)
    {
        for (int i = 0; i < M; i++)
        {
            printf("%d ", print_arr[i]);
        }
        printf("\n");
    }

    else
    {
        for (int i = 0; i < N; i++)
        {
            if (count == 0 || print_arr[count - 1] < arr[i])
            {
                print_arr[count] = arr[i];
                search(count + 1);
            }
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(int), compare);

    search(0);

    return 0;
}