#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    char name[21];
}ALL;

typedef struct 
{
    char name[21];
}OVERLAP;

int compare(const void *a, const void *b)
{
    ALL A = *(ALL*)a, B = *(ALL*)b;
    
    if(strcmp(A.name, B.name) > 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

/* 크기가 1000000이상으로 선언할 것이면 전역변수로 선언해야 선언이 가능하다 */
ALL all[1000001];
OVERLAP overlap[500000];

int main()
{
    int N, M;
    
    scanf("%d %d", &N, &M);

    
    for(int i = 0; i < N+M; i++)
    {
        scanf("%s", all[i].name);
    }

    qsort(all, N+M, sizeof(ALL), compare);

    int count = 0;
    for(int i = 0; i < N+M-1; i++)
    {
        /*검사할 인덱스와 다음 인덱스가 같을 때*/
        if(strcmp(all[i].name, all[i+1].name) == 0)
        {
            /*첫번째이거나 그 전 인덱스와 다르다면(중복입력방지)*/
            if(strcmp(all[i].name, all[i-1].name) != 0 || i == 0)
                strcpy(overlap[count++].name, all[i].name);
        }
    }


    printf("%d\n", count);
    for(int i = 0; i < count; i++)
    {
        printf("%s\n", overlap[i].name);
    }


    return 0;
}