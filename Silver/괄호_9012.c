#include <stdio.h>
#include <string.h>

int check(char*PS);

int main()
{
    int N;
    char PS[51]; 
    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%s", PS);
        check(PS);
    }


    return 0;
}

int check(char*PS)
{
    /* 닫는 괄호가 나왔을 때 여는 괄호가 존재하지 않는다면 No출력 */
    /* ((만 있거나 ))만 있는 경우에도 NO가 나와야 함*/
    int len = strlen(PS);
    int open = 0;
    for(int i = 0; i < len; i++)
    {
        if(PS[i] == '('){
            open++;
        }
        else if(PS[i] == ')')
        {
            /* 종료조건, )가 나왔는데 (가 없는 경우 */
            if(open == 0){
                printf("NO\n");
                return 0;
            }
            else{
                open--;
            }
        }
    }
    /* 마지막이 (로 끝나는 경우 */
    if(open != 0)
    {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    
    return 0;
}