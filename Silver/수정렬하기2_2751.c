#include <stdio.h>
#include <stdlib.h>

void merge(int *ARR, int low, int mid, int high);

void mergeSort(int *ARR, int low, int high);

int main()
{
    int N;
    scanf("%d", &N);

    int *ARR = NULL, *p;
    ARR = (int*)malloc(sizeof(int)*N);

    for(p = ARR; p < ARR + N; p++)
    {
        scanf("%d", p);
    }

    mergeSort(ARR, 0, N-1);

    /*결과값 출력*/

    for(p = ARR; p < ARR + N; p++)
    {
        printf("%d\n", *p);
    }

    free(ARR);

    return 0;
}

void merge(int *ARR, int low, int mid, int high)
{
    int *arr = NULL, size = high - low + 1;
    arr = (int*)malloc(sizeof(int)*size);
    int i = low, j = mid + 1, k = 0;

    while(i <= mid && j <= high)
    {
        if(ARR[i] <= ARR[j]){
            arr[k++] = ARR[i++];
        }
        else{
            arr[k++] = ARR[j++];
        }
    }
    while(i <= mid)
        arr[k++] = ARR[i++];
    while(j<=high)
        arr[k++] = ARR[j++];

    k--;
    
    while(k >= 0)
    {
        ARR[low+k] = arr[k];
        k--;
    }
    free(arr);
}

void mergeSort(int *ARR, int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (low+high) / 2;
        mergeSort(ARR, low, mid);
        mergeSort(ARR, mid+1, high);
        merge(ARR, low, mid, high);
    }
}
