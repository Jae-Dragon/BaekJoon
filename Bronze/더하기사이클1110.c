#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    int t1 = 0, t2 = 0, count = 0, init = 0, t = 0;

    init = N;
    
    do{
        t1 = N / 10;
        t2 = N % 10;

        t = t1 + t2;

        N = t2 * 10 + t % 10;
        
        count++;

    }while(init != N);
   

    printf("%d", count);

    return 0;
}