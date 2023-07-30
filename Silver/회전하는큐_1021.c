#include <stdio.h>

int Q[50];

int N, M, cnt = 0;

/* 양방향 큐라고 하는데 앞에서만 빼야 문제가 풀린다. */
void DeQue();
void Rotate_Left();
void Rotate_Right();
/* 인덱스의 위치 파악 */
int FindIndex(int find);

int main()
{

    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++)
    {
        Q[i] = i;
    }

    for (int i = 0; i < M; i++)
    {
        int find;
        scanf("%d", &find);

        int find_index = FindIndex(find);

        int g;

        /* 홀수일 때와 짝수일 때 기준점을 다르게 잡아줘야 한다. */
        if(N % 2 == 0)
        {
            g = N / 2;
        }
        else 
        {
            g = N / 2 + 1;
        }

        /* 찾는 인덱스가 기준점 앞에 있을 경우 */
        if (find_index <= g)
        {
            while (Q[1] != find)
            {
                Rotate_Left();
                cnt++;
            }
            DeQue();
        }
        /* 찾는 인덱스가 기준점 뒤에 있을 경우 */
        else
        {
            while (Q[1] != find)
            {
                Rotate_Right();
                cnt++;
            }
            DeQue();
        }
    }
    printf("%d", cnt);

    return 0;
}

void DeQue()
{
    for (int i = 1; i <= N; i++)
    {
        Q[i] = Q[i + 1];
    }
    N--;
}

void Rotate_Left()
{
    int temp = Q[1];

    for (int i = 1; i < N; i++)
    {
        Q[i] = Q[i + 1];
    }
    Q[N] = temp;
}
void Rotate_Right()
{
    int temp = Q[N];

    for (int i = N; i >= 2; i--)
    {
        Q[i] = Q[i - 1];
    }
    Q[1] = temp;
}

int FindIndex(int find)
{
    for (int i = 1; i <= N; i++)
    {
        if (Q[i] == find)
        {
            return i;
        }
            
    }
    return 0;
}
