#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int age;
    int turn;
    char name[101];
}MEMBER;

int compare(const void *a, const void *b)
{
    MEMBER A = *(MEMBER*)a;
    MEMBER B = *(MEMBER*)b;

    if(A.age > B.age)
    {
        return 1;
    }
    else if (A.age < B.age)
    {
        return -1;
    }
    else
    {
        if(A.turn > B.turn)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    MEMBER *mem;

    mem = (MEMBER*)malloc(sizeof(MEMBER)*N);
        
    for(int i = 0; i < N; i++)
    {
        scanf("%d %s", &mem[i].age, mem[i].name);
        getchar();
        mem[i].turn = i;
    }

    qsort(mem, N, sizeof(MEMBER), compare);


    for(int i = 0; i < N; i++)
    {
        printf("%d %s\n", mem[i].age, mem[i].name);
       
    }
    free(mem);

    return 0;
}