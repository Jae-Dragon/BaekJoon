#include <stdio.h>

int arr[41][2] = {};

void fibonacci(int n) {
    arr[0][0] = 1;
    arr[0][1] = 0;
    arr[1][0] = 0;
    arr[1][1] = 1;

    if (n == 0) {
        printf("%d %d\n", arr[0][0], arr[0][1]);
    } 
    else if (n == 1) {
        printf("%d %d\n", arr[1][0], arr[1][1]);
    } 
    else {
        for(int i = 2; i <= n; i++)
        {
            arr[i][0] = arr[i-1][0] + arr[i-2][0];
            arr[i][1] = arr[i-1][1] + arr[i-2][1];
        }
        printf("%d %d\n", arr[n][0], arr[n][1]);
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        int n;
        scanf("%d", &n);
        fibonacci(n);
    }


    return 0; 
}