#include <stdio.h>
#include <string.h>

int Q[10000];
int top = -1;

void push(int n);
int pop();
void size();
void empty();
void front();
void back();

int main()
{
    int N, t;
    scanf("%d", &N);

    char order[20];

    for(int i = 0; i < N; i++)
    {
        scanf("%s", order);

        if(strcmp("push", order) == 0)
        {
            scanf("%d", &t);
            push(t);
        }
        else if(strcmp("pop", order) == 0)
        {
            printf("%d\n", pop());
        }
        else if(strcmp("size", order) == 0)
        {
            size();
        }
        else if(strcmp("empty", order) == 0)
        {
            empty();
        }
        else if(strcmp("front", order) == 0)
        {
            front();
        }
        else if(strcmp("back", order) == 0)
        {
            back();
        }
    }

    return 0;
}

void push(int n)
{
    Q[++top] = n;
}
int pop()
{
    if(top == -1)
    {
        return -1;
    }
    
    int g = Q[0];

    for(int i = 0; i < top; i++)
    {
        Q[i] = Q[i+1];
    }
    top--;
    
    return g;
}
void size()
{
    printf("%d\n", top+1);
}
void empty()
{
    if(top <= -1) printf("1\n");
    else printf("0\n");
}
void front()
{
    if(top == -1) printf("-1\n");
    else printf("%d\n", Q[0]);
}
void back()
{
    if(top == -1) printf("-1\n");
    else printf("%d\n", Q[top]);
}