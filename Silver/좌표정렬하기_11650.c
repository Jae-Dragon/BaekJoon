#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int x;
    int y;
}POINT;


int compare(const void *a, const void *b)
{
    POINT A = *(POINT*)a;
    POINT B = *(POINT*)b;

    /* 오름차순 정렬 */
    //바꿀겁니까? -> 0 
    if(A.x > B.x)
    {
        return 1;
    }
    //바꿀겁니까? -> x
    else if(A.x < B.x)
    {
        return -1;
    }
    
    //---------------------

    if(A.y > B.y)
    {
        return 1;
    }
    else{
        return -1;
    }

}

int main()
{
    int N;
    scanf("%d", &N);

    POINT point[N];

    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &point[i].x, &point[i].y);
    }
    qsort(point, N, sizeof(POINT), compare);

    for(int i = 0; i < N; i++)
    {
        printf("%d %d\n", point[i].x, point[i].y);
    }

    return 0;
}