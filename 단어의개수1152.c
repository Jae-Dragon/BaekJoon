#include <stdio.h>
#include <string.h>

int main()
{
    char STRING[1000001]; // NULL문자를 생각해줘야함

    scanf("%[^\n]s", STRING); // 일반 %s로는 공백을 받지 못한다
    int len = 0, count = 1;
    len = strlen(STRING);

    if (STRING[0] == ' ')
    {
        count = 0;
    }

    /* 착각하지 말아야 할 것이 공백의 개수가 목적이 아닌 단어의 개수를 세는 것이라는 것을 인지할 것 */
    for (int i = 0; i < len - 1; i++)
    {
        if (STRING[i] == ' ' && STRING[i + 1] != ' ')
        { /* 이 조건일 때 맨 앞이 공백으로 시작하는 것에 예외처리가 필요함 */
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}