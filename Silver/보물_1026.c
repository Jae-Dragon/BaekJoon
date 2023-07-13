#include <stdio.h>
#include <stdlib.h>

void swap(int *A, int *B)
{
    int tmp = 0;
    tmp = *A;
    *A = *B;
    *B = tmp;
}

void bubbleSort(int *arr, int N)
{
    int temp = 0;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main()
{
    int N, A[100], B[100], B_rank[100] = {0};
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &B[i]);
    }

    bubbleSort(A, N); // 오름차순 정렬
  
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (B[i] < B[j])
            {
                B_rank[i]++;
            }
        }
    }

    int rank = 0, total = 0;

    for (int i = 0; i < N; i++)
    {
        int r = 0; // B 순환 횟수 체크
        while (1)
        {
            if (rank == B_rank[r])
            {
                total += A[i] * B[r];
                B_rank[r] = -1;
                break;
            }
            else
            {
                if (r == N - 1)
                {
                    rank++; // A와 곱해줄 랭킹 순위
                    i--;
                    break;
                }
            }
            r++;
        }
    }

    printf("%d", total);

    return 0;
}