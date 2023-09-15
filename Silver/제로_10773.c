#include <stdio.h>

int arr[100000];
int top = -1;

void push(int n);
void pop();

int main()
{
    int N, total = 0, g = 0;
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        int k;
        scanf("%d", &k);
        if(k == 0)
            pop();
        else
            push(k);
       
    }


    for(int i = 0; i <= top; i++)
    {
        total += arr[i];
    }


    printf("%d", total);

    return 0;
}

void push(int n)
{
    arr[++top] = n;
}
void pop()
{
    top--;
}
