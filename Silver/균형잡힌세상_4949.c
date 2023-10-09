#include <stdio.h>
#include <string.h>

char stack[101];
int top = -1;

void push(char bracket);
void pop();

int main()
{  
    while(1)
    {
        /* 지속적인 초기화가 필요하기 때문에 수행 */
        char STRING[101];
        top = -1;
        /* 입력 */
        scanf("%[^\n]s", &STRING); 
        /* 반복문 종료 조건 */
        if(STRING[0] == '.')
        {
            break;
        }
        int len = strlen(STRING);

        /* 스택에 좌측 괄호일 경우에는 넣어주고 우측 괄호일 경우는 꺼내서 짝이 맞는지 확인 */
        for(int i = 0; i < len; i++)
        {
            if(STRING[i] == '(')
            {
                push(STRING[i]);
            }
            else if(STRING[i] == '[')
            {
                push(STRING[i]);
            }
            else if(STRING[i] == ')')
            {
                if(stack[top] == '(')
                {
                    pop();
                }
                else
                {
                    printf("no\n");
                    break;
                }
            }
            else if(STRING[i] == ']')
            {
                if(stack[top] == '[')
                {
                    pop();
                }
                else
                {
                    printf("no\n");
                    break;
                }
            }

            /* 맨 끝에 도달했을 때의 종료 조건 */
            if (STRING[i] == '.')
            {
                if(top == -1)
                {
                    printf("yes\n");
                    break;
                }
                else
                {
                    printf("no\n");
                    break;
                }
                
            }
        }        
        getchar();
    } 

    return 0;
}

void push(char bracket)
{
    stack[++top] = bracket;
}
void pop()
{
    --top;
}
