#include <stdio.h>
#include <string.h>

int main()
{
    int M, N;
    scanf("%d %d", &N, &M);

    char CHESS[50][51];

    for(int i = 0; i < N; i++)
    {
       
        scanf("%s", &CHESS[i]);
        
    }
    /* 한점을 기준으로 잡고 거기서 8x8을 먼저 확인하는 방법 */
    /* 기준 x, y값을 저장하는 좌표, 고쳐야할 점의 최솟값을 저장할 변수 */
    /* 맨 왼쪽 위의 칸이 흰색인 경우와 검은색인 경우로 분리했을 때 짝수칸 홀수칸을 기준으로 바꿔야 한다*/
    int max = 5000;
    int stan_W = 0, stan_B = 0;

    for(int x = 0; x < N - 7; x++)//시작 기준점의 x좌표
    {
        for(int y = 0; y < M - 7; y++)//시작 기준점의 y좌표
        {
           //첫번째칸을 W로 만드는 방법
           for(int i = x; i < x + 8; i++)
           {
            for(int j = y; j < y + 8; j++)
            {
                if((i - x + j - y) % 2 == 0)//짝수일 때는 짝 + 짝, 홀 + 홀인 경우이므로 W여야 함
                {
                    if(CHESS[i][j] != 'W'){//W가 아니면 색칠해줘야 하므로
                        stan_W++;
                    }

                }
                else{
                    if(CHESS[i][j] != 'B'){
                        stan_W++;
                    }
                }
                
            }
           }

           //첫번째칸을 B로 만드는 방법
           for(int i = x; i < x + 8; i++)
           {
            for(int j = y; j < y + 8; j++)
            {
                if((i - x + j - y) % 2 == 0)//짝수일 때는 짝 + 홀, 홀 + 짝인 경우이므로 B여야 함
                {
                    if(CHESS[i][j] != 'B'){//W가 아니면 색칠해줘야 하므로
                        stan_B++;
                    }

                }
                else{
                    if(CHESS[i][j] != 'W'){
                        stan_B++;
                    }
                }   
            }
           }

           int cal = stan_W < stan_B ? stan_W : stan_B;//더 작은 것을 찾고
           if(cal < max) max = cal;

           stan_B = 0; stan_W = 0;//초기화
        }
    }

    printf("%d", max);

    return 0;
}