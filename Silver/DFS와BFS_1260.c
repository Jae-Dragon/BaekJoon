#include <stdio.h>
#include <string.h>

#define num_vertex 1001

int graph[num_vertex][num_vertex], visit_DFS[num_vertex], visit_BFS[num_vertex];

void DFS(int V, int N)
{
    visit_DFS[V] = 1;
    printf("%d ", V);
    for(int i = 1; i <= N; i++)
    {
        if(graph[V][i] == 1 && visit_DFS[i] == 0)
        {
            DFS(i, N);
        }
    }

}

void BFS(int V, int N)
{
    visit_BFS[V] = 1;
    printf("%d ", V);
    int front = 0, rear = 1, queue[num_vertex], pop;

    queue[0] = V;

    while(front < rear)
    {
        pop = queue[front++];

        for(int i = 1; i <= N; i++)
        {
            if(graph[pop][i] == 1 && visit_BFS[i] == 0)
            {
                printf("%d ", i);
                visit_BFS[i] = 1;
                queue[rear++] = i;
                         
            }
        }
    }

}

int main()
{
    int N, M, V;

    scanf("%d %d %d", &N, &M, &V);

    int x, y;

    for(int i = 0; i < M; i++)
    {
        scanf("%d %d", &x, &y);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    DFS(V, N);
    printf("\n");
    BFS(V, N);
    
    

    return 0;
}