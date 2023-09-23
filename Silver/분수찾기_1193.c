#include <stdio.h>
#define SIZE 10000000

int main()
{
    int N, prime = 0;
    
    scanf("%d", &N);
    if(N == 1)
    {
        printf("1/1\n");
        return 0;
    }

    for(int i = 1; i < SIZE; i++)
    {
        int g = (i*(i+1)) / 2;

        if(N <= g)
        {
            prime = i;
            break;
        }
    }

    int re = (prime*(prime-1)) / 2;

    int left = 0, right = 0;
    
    if(prime % 2 == 0)
    {
        left = 1; right = prime;

        while(N - re > 1)
        {
            left++;
            right--;
            N--;
        }
    }

    else
    {
        left = prime; right = 1;
        
        while(N - re > 1)
        {
            left--;
            right++;
            N--;
        }
    }

    printf("%d/%d",left, right);

    return 0;
}