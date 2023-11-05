#include <stdio.h>

int stack[100000];
int top = -1;

void push(int N)
{
    stack[++top] = N;
}

int pop()
{
    int N = stack[top--];
    return N;
}

int main()
{
    /* 문제는 일단 스택에 1~N까지의 수를 넣고 주어진 수열을 그 스택에서의 push와 pop을 통해 만들 수 있는가 */
    int N;
    scanf("%d", &N);

    char pushpop[400000];
    /* NO가 되는 조건은 pop을 해야할 때 주어진 숫자 뒤에 정수가 있는 경우에 안됨    ex) 1 2 6 4 5순일 경우 6을 pop한 뒤에 5가 있어서 4를 추출할 수가 없다 */
    /* 앞에 주어진 N보다 뒤에 주어진 N이 작을 때 pop을 했을 때 그 수가 아니라면 NO */

    int g, index = 0, index_pp = 0;

    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &g);

        if (index > g)
        {
            int con = pop();
            if (con != g)
            {
                printf("NO\n");
                return 0;
            }
            pushpop[index_pp++] = '-';
        }
        else
        {
            while (index < g)
            {   
                push(++index);
                //printf("push: %d\n",index);
                pushpop[index_pp++] = '+';
            }
            int con = pop();
            pushpop[index_pp++] = '-';
        }
    }

    for (int i = 0; i < index_pp; i++)
    {
        printf("%c\n", pushpop[i]);
    }

    // 4 3 6 8 7 5 2 1
    // 1 2 3 4(push) 4 3(pop) 5 6(push) 6(pop) 7 8(push) 8 7 5 2 1(pop)

    return 0;
}