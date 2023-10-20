#include <stdio.h>
#define MAX (a)>(b) ? (a):(b)

typedef struct 퇴사_14501
{
    int request_day;
    int pay;
}DATA;

int N;
int MAX_PAY;

void CONSULT(DATA* data, int sum, int count)
{
    /* 최대 받을 수 있는 돈 갱신 */
    if(sum > MAX_PAY)
    {
        MAX_PAY = sum;
    }

    /*맨 처음 1일차부터 돈을 받을 수 있는 경우의 수를 구한다 (브루트포스) */
    while(count <= N)
    {
        if(data[count].request_day + count <= N+1)
        {
            CONSULT(data, sum+data[count].pay, count+data[count].request_day);
        }
        /* 당일 쉬고 다음날부터 했을 때로 이동 */
        count++;
    }

}

int main()
{
    scanf("%d", &N);
    DATA data[N+1];

    for(int i = 1; i <= N; i++)
    {
        scanf("%d %d", &data[i].request_day, &data[i].pay);
    }

    MAX_PAY = 0;

    CONSULT(data, 0, 1);

    printf("%d", MAX_PAY);

    return 0;
}