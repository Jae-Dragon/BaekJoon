#include <stdio.h>
#include <string.h>


int main()
{
    char str[51], plus_minus[51];
    scanf("%s", str);

    int len = strlen(str), total = 0, str_num[51];

    /* 가장 최솟값이 나오는 경우가 뭘까 */
    /* - 뒤에 +가 많이올수록 */
    /* 4 - 5 + 6 + 7 + 8 - 9 */
    /* 4-(5+6+7+8)-9 */
    /* 일단 배열에 숫자를 저장하고 total에 +는 그냥 더해주고 -가 나올 때 +가 나오면 계속 더해주고 한번에 빼줘야 할듯 */

    int char_num = 0, num = 0;

    for(int i = 0; i < len; i++)
    {
        if(str[i] == '+' || str[i] == '-')
        {
            plus_minus[char_num++] = str[i];
        }      
        else
        {
            int g = str[i] - '0';
            while(i <= len-2 && str[i+1]-'0' >= 0 && str[i+1]-'0' <= 9)
            {
                g *= 10;
                g += str[++i] - '0';
            }
            str_num[num++] = g;           
        }
    }

    // for(int i = 0; i < char_num; i++)
    // {
    //     printf("%c ", plus_minus[i]);
    // }
    // printf("\n");
    
    // for(int i = 0; i < num; i++)
    // {
    //     printf("%d ", str_num[i]);
    // }

    total = str_num[0];
    int g = 1;
    for(int i = 0; i < char_num; i++)
    {
        if(plus_minus[i] == '+')
        {
            total += str_num[g++];
        }
        else
        {
            int flag = str_num[g++];
            
            while(g <= num-1 && plus_minus[i+1] == '+')
            {
                flag += str_num[g++];
                i++;
            }
            //printf("\nflag: %d\n", flag);
            total -= flag;
        }
    }

    printf("%d\n", total);


    return 0;
}