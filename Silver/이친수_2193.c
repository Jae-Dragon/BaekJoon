#include <stdio.h>

typedef struct 이친수_2193
{
    long long num_0;
    long long num_1; 

}pinary_num;

int main()
{
    int N;
    long long arr[91];

    pinary_num ARR[91];

    scanf("%d", &N); 
    
    /* 0으로 시작 x, 1이 연속해서 나타나지 않음 */
    /* DP문제 */
    /* 뒤에가 0으로 끝나면 뒤에 올 수 있는 경우의 수는 2개, 1로 끝나면 1개 */
    /* 그 다음 자릿수의 0으로 끝나는 수의 개수는 이전 자릿수의 0의 개수 + 이저 자릿수의 1의 개수 */
    /* 그 다음 자릿수의 1의 개수는 이전 자릿수의 0의 개수 */
    arr[1] = 1;//1 // 0 1
    arr[2] = 1;//10 // 0 1
    arr[3] = 2;//101, 100 // 1 1
    arr[4] = 3;//1010, 1001, 1000 // 2 1
    arr[5] = 5;//10101, 10100, 10010, 10000, 10001 // 3 2
    arr[6] = 8;//101010,/ 101001, 101000, /100101, 100100,/ 100000, 100001, /100010 //5 3
    //arr[7] = 14//9 5


    ARR[1].num_0 = 0;
    ARR[1].num_1 = 1;
    ARR[2].num_0 = 0;
    ARR[2].num_1 = 1;
    ARR[3].num_0 = 1;
    ARR[3].num_1 = 1;  

    for(int i = 4; i <= N; i++)
    {
        ARR[i].num_0 = ARR[i-1].num_0 + ARR[i-1].num_1;
        ARR[i].num_1 = ARR[i-1].num_0;
    }   
    

    for(int i = 1; i <= N; i++)
    {
       arr[i] = ARR[i].num_0 + ARR[i].num_1;
    }
    printf("%lld", arr[N]);


    return 0;
}