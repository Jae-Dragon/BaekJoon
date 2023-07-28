#include <stdio.h>
#include <math.h>

int main()
{
    int T, N, x1,x2,y1,y2;
    scanf("%d", &T);

    for(int i = 0; i < T; i++)
    {
        int cnt = 0;//진입 및 이탈 횟수

        /* 어린왕자의 출발점, 도착점 */
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        scanf("%d", &N);

        for(int j = 0; j < N; j++)
        {
            /* 내부에 있을 때랑 외부에 있을 때를 나눠야 할까 */
            /* 도착점과 시작점이 원의 방정식 내에 있는지만 확인하면 된다 */
            int cir_x, cir_y, r;
            scanf("%d %d %d", &cir_x, &cir_y, &r);
            
            if(pow(x1-cir_x, 2) + pow(y1-cir_y, 2) < pow(r,2) && pow(x2-cir_x, 2) + pow(y2-cir_y, 2) < pow(r,2))
            {
                continue;
            }

            else if(pow(x1-cir_x, 2) + pow(y1-cir_y, 2) < pow(r,2))
            {
                cnt++;
            }
            else if(pow(x2-cir_x, 2) + pow(y2-cir_y, 2) < pow(r,2))
            {
                cnt++;
            }

        }
        printf("%d\n", cnt);

    }


    return 0;
}