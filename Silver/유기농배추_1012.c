#include <stdio.h>

int t, N, M, k ;

void DFS(int x, int y, int arr[51][51])
{
    if (x == M && y == N || arr[y][x] == 0)
    {
        return;
    }
    else
    {              
        arr[y][x] = 0;
        if(x >= 1)
            DFS(x-1, y, arr);
        if(y >= 1)
            DFS(x, y-1, arr);
        DFS(x+1, y, arr);
        DFS(x, y+1, arr);       
    }
}

int main()
{
    scanf("%d", &t);

    for (int j = 0; j < t; j++)
    {
        scanf("%d %d %d", &M, &N, &k);

        int x, y, count = 0, arr[51][51] = {0,};
        for (int i = 0; i < k; i++)
        {
            scanf("%d %d", &x, &y);
            arr[y][x] = 1;
        }

        /* 1이 모여있는 곳당 카운트를 한개씩 올려주면 된다 */

        for (int i = 0; i < N; i++)
        {
            for (int g = 0; g < M; g++)
            {
                if(arr[i][g] == 1)
                {
                    count++;
                    DFS(g,i, arr);
                }
            }
        }   
        printf("%d\n", count);
    }

 

    return 0;
}