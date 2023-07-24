#include <stdio.h>

int selfNum(int N);//셀프넘버가 아닌 것을 구하는 함수

int main()
{
    /* 1. 셀프 넘버를 구하고 반복문 돌려서 아닌 것들만 판명? */
    /* 셀프넘버의 성질: 자기 자신보다는 무조건 큼 */


    int arr[10000] = {0}, a = 0;


    for (int i = 1; i < 10000; i++) /* 셀프 넘버를 먼저 구하자 */
    {
        if(selfNum(i) < 10001)/*셀프넘버가 아닌 수의 배열의 칸에는 1을 넣어줘서 1인 것들은 이제 셀프넘버가 아닌 걸로 알 수 있음 */
        {
            arr[selfNum(i)] = 1;
        }

    }
    
    int k = 1;

    for (int i = 1; i < 10000; i++)
    {
        if(arr[i] != 1)
            printf("%d\n", i);
    }
    
    return 0;
}

int selfNum(int N)
{
    int result = N;

    while (N > 0)
    {
        result += N % 10;
        N /= 10;
    }
    return result;
}

 
