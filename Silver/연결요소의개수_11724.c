#include <stdio.h>
#define num_vertex 1001

int graph[num_vertex][num_vertex], visit_DFS[num_vertex];
int COUNT = 0;

void DFS(int i, int N)
{
    visit_DFS[i] = COUNT;
    for (int j = 1; j <= N; j++)
    {
        if (graph[i][j] == 1 && visit_DFS[j] == 0)
            DFS(j, N);
    }

}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    int x, y;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &x, &y);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    for(int i = 1; i <= N; i++)
    {
        if(visit_DFS[i] == 0)
        {
            COUNT++;
            DFS(i, N);   
        }
            
    }
    int max = 0;

    for(int i = 1; i <= N; i++)
    {
        if(visit_DFS[i] > max)
        {
            max = visit_DFS[i];
        }
    }

    // for(int i = 1; i <= N; i++)
    // {
    //     printf("i: %d, max: %d\n", i, visit_DFS[i]);
    // }

    printf("%d\n", max);

    return 0;
}