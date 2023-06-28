#include <stdio.h>
#include <string.h>

int main()
{
    char WORD[20000][50];
    int N, word[20000] = {0};
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%s", WORD[i]);
    }
    //내가 생각한 방법
    /* 우선 WORD랑 똑같은 크기 int 배열을 하나 만들고 거기에 strlen을 통해 각 방에 있는 단어의 길이를 저장 */
    /* 길이가 같을 경우 1. 중복인지 확인, 2. 맞으면 그 방을 삭제, 3. 아닐경우 사전 상 어떤지 비교 */
    for(int i = 0; i < N; i++)//단어의 길이를 저장
    {
        word[i] = strlen(WORD[i]);//word에는 단어의 길이를 저장
        int len = word[i];

        for(int j = 0; j < i; j++)
        {
            int G = word[j];
            if(len == G)//길이가 같을 경우
            {
                if(strcmp(WORD[i], WORD[j]) == 0){//중복되는 경우
                    word[j] = 0;//뒤에 중복되는 항목의 길이에 0을 넣어둠
                }
                else if(strcmp(WORD[i], WORD[j]) < 0)//길이는 같으나 앞에 것이 사전상 더 앞일 경우
                {
                    
                }

            }

        }
    }


    return 0;
}