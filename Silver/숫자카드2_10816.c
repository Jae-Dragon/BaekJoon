#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
    int n1 = *(int*)a, n2 = *(int*)b;
    if (n1 < n2)
        return -1;
    else if (n1 > n2)
        return 1;
    return 0;
}

int lower_bound(int *arr, int find, int N);
int upper_bound(int *arr, int find, int N);

int main()
{
    int N, M, g;
    scanf("%d", &N);
    int arr[N];

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &g);
        arr[i] = g;
    }
    
    qsort(arr, N, sizeof(int), compare);
    
   
    scanf("%d", &M);

    for(int i = 0; i < M; i++)
    {
        scanf("%d", &g);
        printf("%d ", upper_bound(arr, g, N)-lower_bound(arr, g, N));
    }


    return 0;
}

/* 키 값이 없으면 키 값보다 큰 가장 작은 정수를 반환 */
int lower_bound(int *arr, int find, int N)
{
    int start, end, mid, count = 0;
    start = 0;
    end = N - 1;

    while(start < end)
    {
        mid = (end+start) / 2;
        // 1 2 3 4 5 6 7
        if(arr[mid] < find)
        {
            start = mid + 1;
        }
        else{
            end = mid;
        }
    }
    return end;
}

/* 키 값을 초과하는 가장 첫 번째 원소의 위치를 반환 */
int upper_bound(int *arr, int find, int N)
{
    int start, end, mid, count = 0;
    start = 0;
    end = N - 1;

    while(start < end)
    {
        mid = (end+start) / 2;
        // 1 2 3 4 5 6 7
        if(arr[mid] <= find)
        {
            start = mid + 1;
        }
        else{
            end = mid;
        }
    }
    if(arr[end] == find)
    {
        return end + 1;
    }

    return end;
}