#include <stdio.h>

int VIRUS[101][101], check[101] = {0}, cnt = 0;

void DFS(int start, int end);

int main()
{
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);

    for (int i = 0; i < M; i++)
    {
        int L, R, t = 0;
        scanf("%d %d", &L, &R);
        /* 양방향 연결 설정 */
        VIRUS[L][R] = 1; VIRUS[R][L] = 1;
    }

    /* 깊이 우선 탐색을 통해 연결된 컴퓨터를 찾는다 */
    DFS(1, N);

    /* 1번 컴퓨터는 카운트에서 제외해야 하므로*/
    printf("%d", cnt-1);
    
    return 0;
}

void DFS(int start, int end)
{
    /* 들어온 start는 방문한 것이므로 */
    check[start] = 1;
    cnt++;

    /* 0번 인덱스는 비어놓고 시작했다는 것을 잊으면 안됨, 1부터 시작하기 때문 */
    for(int i = 1; i <= end; i++)
    {
        /* 앞서 양방향으로 설정된 것은 1로 지정했고 아직 방문하지 않은 인덱스일 경우 */
        if(VIRUS[start][i] == 1 && check[i] == 0)
        {
            /* 이제 출발점이 i가 된다고 생각하면 편하다 */
            DFS(i, end);
        }
    }

    /* 1부터 시작했기 때문에 1과 연결되지 않은 4와 7은 가지 않는다 */

    return;
}