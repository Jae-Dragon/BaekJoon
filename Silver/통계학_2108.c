#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

typedef struct 통계학_2108
{
    /* 입력된 숫자 */
    int data;
    /* 입력된 숫자가 출연한 빈도의 수 */
    int amount_of_data;
} MODE;

int compare_1(const void *a, const void *b)
{
    /* 중앙값 도출을 위해 오름차순 정렬 */
    int A = *(int *)a;
    int B = *(int *)b;

    /* 안바꿔도 되면 -1, 바꿔야 하면 1 리턴*/
    if (A < B)
    {
        return -1;
    }
    else
        return 1;
}

int compare_2(const void *a, const void *b)
{
    MODE A = *(MODE *)a;
    MODE B = *(MODE *)b;

    /* 인덱스에 출연한 개수를 비교하여 출연한 빈도가 큰 것을 앞으로 보내줌 (내림차순 정렬) */
    if (A.amount_of_data > B.amount_of_data)
    {
        return -1;
    }
    else if (A.amount_of_data < B.amount_of_data)
    {
        return 1;
    }
    /* 출연 빈도가 같다면 데이터의 크기대로 오름차순 정렬 */
    else
    {
        if (A.data < B.data)
        {
            return -1;
        }
        else
            return 1;
    }
}

/* 산술 평균 도출 */
int arith_mean(int *arr, int N){ 
    double sum=0;
    for(int i=0; i<N; i++){
        sum += arr[i];
    }
    return (int)round(sum/N);
}

int main()
{
    int N, sum = 0, range = 0, mid = 0, max = INT_MIN, min = INT_MAX;
    scanf("%d", &N);

    int arr[N];

    MODE mode[8001];

    /* 0~4000까지는 그대로, 그 이후부터는 그 수에서 -4000을 뺴고 -1을 곱해준다. */
    for (int i = 0; i <= 8000; i++)
    {
        if (i <= 4000)
        {
            mode[i].data = i;
            mode[i].amount_of_data = 0;
        }
        else
        {
            mode[i].data = (i - 4000) * (-1);
            mode[i].amount_of_data = 0;
        }
    }


    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);

        sum += arr[i]; // 산술평균 구하기 위한 초석

        if (max < arr[i])
            max = arr[i]; // 범위를 구하기 위한 초석
        if (min > arr[i])
            min = arr[i];

        /* 최빈값을 구하기 위한 초석 */
        if (arr[i] >= 0)
        {
            mode[arr[i]].amount_of_data++;
        }
        else
        {
            int g = (arr[i]) * (-1) + 4000;
            mode[g].amount_of_data++;
        }
    }

    /* 산술평균의 결과값 도출 */
    int arithmetic_mean = arith_mean(arr, N);

    /* 중앙값의 인덱스 도출 */
    mid = N / 2;
    qsort(arr, N, sizeof(int), compare_1);

    /* 최빈값의 인덱스 도출 */
    qsort(mode, 8001, sizeof(MODE), compare_2);

    /* 범위 도출 */
    range = max - min;

    /* 출력 */
    printf("%d\n", arithmetic_mean);
    printf("%d\n", arr[mid]);
    if (mode[0].amount_of_data != mode[1].amount_of_data)
    {
        printf("%d\n", mode[0].data);
    }
    else
    {
        printf("%d\n", mode[1].data);
    }
    printf("%d\n", range);
   
    return 0;
}