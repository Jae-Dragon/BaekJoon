#include <stdio.h>

int main()
{
    int N;
    int k = 123456, k1 = k*2;

    int arr[(k1+1)*2];

    arr[1] = 1;

    for(int i = 2; i <= k1+1; i++)
    {
        for(int j = 2; j <= k1+2; j++)
        {
            /* 최댓값보다 작고 소수가 아니라면 */
            if(i*j <=k1+2)
            {
                arr[i*j] = 1;
            }
            else
                break;
        }
    }

    while(1)
    {
       scanf("%d", &N);
       if(N == 0)
       {
            break;
       }
       int count = 0;

       for(int i = N+1; i <= 2*N; i++)
       {
            if(arr[i] == 0)
            {
                count++;
            }
       }        
       printf("%d\n", count);   

    }



    return 0;
}