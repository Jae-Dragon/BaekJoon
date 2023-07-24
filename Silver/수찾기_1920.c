#include <stdio.h>
#include <time.h>
#include<stdlib.h>

int compare(const void *a, const void *b)
{
    return *(int*)a > *(int*)b ? 1 : (*(int*)a < *(int*)b ? -1 : 0);
}

int main()
{
    int A[100000] = {0}, B[100000] = {0};

    int N, M;
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    scanf("%d", &M);

    /* 찾고 싶은 값(키값)을 저장할 배열 */
    for(int i = 0; i < M; i++)
    {
        scanf("%d", &B[i]);
    }    
    
    /* stdlib.h에 있는 qsort활용 */
    qsort(A, N, sizeof(int), compare);

    /* 이진 배열 트리 활용 */
    for(int i = 0; i < M; i++)
    {
        if(B[i] > A[N-1] || B[i] < A[0]){
            printf("0\n");
            continue;
        }
        
        /* 수의 존재 여부를 체크할 flag 변수 */
        int front = 0, rear = N - 1, flag = 0;

        while(1)
        {
            int pivot = (front + rear) / 2;

            /* 그 수가 존재할 경우 */
            if(A[pivot] == B[i])
            {
                flag = 1;
                break;
            }
            /* 피벗(중심)값보다 키 값이 클 경우 */
            else if(A[pivot] < B[i]){
 
                front = pivot + 1;
            }
            /* 피벗보다 키 값이 작을 경우 */
            else{
                rear = pivot - 1;
            }

            /* 찾지 못했을 때의 종료 조건 */
            if(front > rear){
   
                break;
            }
        }
        printf("%d\n", flag);

    }

    return 0; 
}

