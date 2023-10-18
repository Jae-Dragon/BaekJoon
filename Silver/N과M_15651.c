#include <stdio.h>

int arr[9];
int N, M;

void search(int cnt)
{
    if(cnt == M)
    {
        for(int i = 0; i < M ; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");        
    }
    else
    {
        for(int i = 1; i <= N; i++)
        {           
            arr[cnt] = i;
            
            search(cnt+1);
        }
    }
}

int main()
{
    /*1~N까지의 자연수 중에서 M개를 뽑으면 된다 */
    scanf("%d %d", &N, &M);

    search(0);

    return 0;
}