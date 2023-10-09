#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    int num;
    char name[21];
}POKEMON;


int compare(const void *a, const void *b)
{
    POKEMON *A = (POKEMON*)a;
    POKEMON *B = (POKEMON*)b;

    if(strcmp(A->name, B->name) > 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    char g[21];

    POKEMON *pokemon = NULL, *pokemon_NUM = NULL;

    pokemon = (POKEMON*)malloc(N*sizeof(POKEMON));
    pokemon_NUM = (POKEMON*)malloc(N*sizeof(POKEMON));

    for(int i = 0; i < N; i++)
    {
        scanf("%s", pokemon_NUM[i].name);
        pokemon[i].num = pokemon_NUM[i].num = i + 1;
        pokemon[i] = pokemon_NUM[i];
    }

    qsort(pokemon, N, sizeof(pokemon[0]), compare);

    // printf("===================\n");

    // for(int i = 0; i < N; i++)
    // {
    //     printf("POK[%d]: %s\n", pokemon[i].num, pokemon[i].name);
    // }


    for(int i = 0; i < M; i++)
    {
        scanf("%s", g);
        /* 알파벳으로 들어왔을 때 qsort함수로 알파벳순으로 정리해놓고 이중탐색으로 찾아야 시간초과를 피할 수 있을 듯 */
        if(g[0] < '0' || g[0] >'9')
        {
            int start = 0, end = N-1;
            int mid;
            while(end >= start)
            {
                mid = (start + end) / 2;
                if(strcmp(pokemon[mid].name, g) == 0)
                {
                    printf("%d\n", pokemon[mid].num);
                    break;
                }
                // 1 2 3 4 5 6
                else if(strcmp(pokemon[mid].name, g) > 0)
                {
                    end = mid-1;
                }
                else
                {
                    start = mid+1;
                }
            }
        }
        else
        {
            int r = atoi(g);
            printf("%s\n", pokemon_NUM[r-1].name);
        }
    }

    free(pokemon);
    free(pokemon_NUM);

    return 0;
}