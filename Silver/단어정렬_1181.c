#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int str1 = strlen((char*)a);
    int str2 = strlen((char*)b);

    if(str1 < str2)
    {
        return -1;
    }
    else if(str1 > str2)
    {
        return 1;
    }
    else
        return strcmp((char*)a, (char*)b);
}

int main()
{
    int N;
    scanf("%d", &N);

    char WORD[N][51];
    int check[20001] = {0,};

    for(int i = 0; i < N; i++)
    {
        scanf("%s", WORD[i]);
    }
    qsort(WORD, sizeof(WORD) / sizeof(WORD[0]), sizeof(WORD[0]), compare);

    for(int i = 0; i <= N - 2; i++)
    {
        if(strcmp(WORD[i], WORD[i+1]) == 0)
        {
            check[i+1] = 1;
        }
    }

    for(int i = 0; i < N; i++)
    {
        if(check[i] == 0)
            printf("%s\n", WORD[i]);
    }

    return 0;
}