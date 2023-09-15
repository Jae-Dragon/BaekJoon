#include <stdio.h>
#include <stdlib.h>

int compare(void *first, void *second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else 
        return 0;
}

int main()
{
    int N, *arr, *p;
    scanf("%d", &N);


    arr = (int*)malloc(sizeof(int) * N);

    for(p = arr ; p < arr + N; p++)
    {
        scanf("%d", p);
    }

    qsort(arr, N, sizeof(int), compare);

    int t = 0;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            t+=arr[j];
        }
    }

    printf("%d", t);

    free(arr);

    return 0;
}