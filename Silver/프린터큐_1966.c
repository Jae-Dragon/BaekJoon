#include <stdio.h>
#include <stdlib.h>

int size = -1;

int compare(const void *a, const void *b)
{
    int A = *(int *)a;
    int B = *(int *)b;

    if (A < B)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void insertQueue(int*Queue, int*arr);
void pop(int*Queue);
void relocation(int*Queue);

int main()
{
    int N, M, T;

    scanf("%d", &T);

    /* 가정: 일단 내림차순으로 정렬을 해놓고 하는가 -> 정한 인덱스가 몇번째로 나오는 지이므로 불가능 */
    /* 정해진 인덱스의 위치를 기억하고 차례대로 deque해서 기억하고 있는 인덱스가 몇번째로 나오는지 확인? */
    

    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &N, &M);

        int Queue[101] = {0};
        int arr[101] = {0};
        size = -1;

        for (int j = 0; j < N; j++)
        {
            insertQueue(Queue, arr);
        }

        qsort(arr, N, sizeof(int), compare);    
       
        /* cnt는 출력 순서 */
        int cnt = 0, plag = 0;

        /* 여기서 큐의 맨 앞의 수가 지금 당장 빼야하는 수인지 파악하고 */
        /* 바로 빼야하는 수일 경우 -> 내가 찾는 수랑 일치하면 프린트, 아니면 pop */
        /* 바로 빼야하는 수가 아닐경우 -> 재배치 */
        while (cnt < N && plag == 0)
        {
            for (int i = 0; i <= size; i++)
            {
                if (arr[cnt] == Queue[0])
                {
                    if (M == 0)
                    {
                        printf("%d\n", cnt + 1);
                        plag = 1;
                  
                    }
                    else
                    {
                        pop(Queue);
                        /* 전체가 하나 줄은 거니까 M을 앞으로 한칸 땡겨줌 */
                        M--;
                        cnt++;
                    }
                    /* 어차피 arr에 있는 값은 날려버렸기 때문 */
                    
                    break;
                }
                else
                {
                    /* 맨 끝자리로 이동 */
                    if (M == 0)
                    {
                        M = size;
                       
                    }
                    else
                    {
                        M--;                    
                    }
                    /* 재배치 */
                    relocation(Queue);
                }
            }
            
        }
    }

    return 0;
}

void insertQueue(int*Queue, int*arr)
{
    int N;
    scanf("%d", &N);
    Queue[++size] = N;
    arr[size] = N;
}

void pop(int*Queue)
{
    for (int i = 0; i < size; i++)
    {
        Queue[i] = Queue[i + 1];
    }
    size--;
}

void relocation(int*Queue)
{
    int g = 0;

    g = Queue[0];

    for (int i = 0; i < size; i++)
    {
        Queue[i] = Queue[i + 1];
    }

    Queue[size] = g;

}