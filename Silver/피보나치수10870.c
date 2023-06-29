#include <stdio.h>

int fibonacc5(int n);

int main()
{
    int n;
    scanf("%d", &n);

    printf("%d", fibonacc5(n));

    return 0;
}

int fibonacc5(int n)
{
    if(n == 0) return 0;
    else if (n == 1) return 1;
    else{
        return (fibonacc5(n-2) + fibonacc5(n-1));
    }
}
