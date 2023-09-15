#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int top = -1;
int Stack[10001];//스택

void push(int n)
{
    Stack[++top] = n;
}
void pop()
{
    if(top == -1)
    {
        printf("-1\n");
    }
    else
        printf("%d\n", Stack[top--]);
}

int main()
{
    int N;
    scanf("%d", &N);
    char order[20];

    for(int i = 0 ; i < N; i++)
    {
        scanf("%s", order);

        if(strcmp("pop", order) == 0)
        {
            pop();
        }
        else if(strcmp("size", order) == 0)
        {
            printf("%d\n", top+1);
        }
        else if(strcmp("empty", order) == 0)
        {
            if(top <= -1){
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
        }
        else if(strcmp("top", order) == 0)
        {
            if(top <= -1)
            {
                printf("-1\n");
            }
            else{
                printf("%d\n", Stack[top]);
            }
        }
        
        else if(strncmp("push", order, 4) == 0)
        {
            int n;
            scanf("%d", &n);
            push(n);
        }
        
    }
    return 0;
}