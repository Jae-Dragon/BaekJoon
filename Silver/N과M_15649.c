#include <stdio.h>

void search(int *arr, int count, int N, int M);

int main()
{
    int N, M, arr[9] = {0};

    /* N은 자연수의 범위, M은 출력할 수열의 길이이다. */
    scanf("%d %d", &N, &M);

    search(arr, 0, N, M);
  
    return 0;
}

void search(int *arr, int count, int N, int M)
{
    /* count는 재귀 반복 횟수 혹은 배열 arr에 값을 채운 횟수이다 */
    if(count == M)
    {
        /* 출력할 수열: arr */
        for(int i = 0; i < M; i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");

    }
    else{
        for(int i = 1; i <= N; i++)
        {
            int check = 0;

            /* 출력용 배열 arr에 i가 들어가 있는지 확인 */
            for(int j = 0 ; j < count; j++)
            {
                if(arr[j] == i){
                    check = 1;
                }
                
            }
            /* 앞서 i가 이미 출력용 배열 arr에 들어가 있지 않다면 */
            if(!check){
                arr[count] = i;
                search(arr,count+1, N, M);
            }
        }
    }
}