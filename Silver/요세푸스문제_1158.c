#include <stdio.h>

int main()
{
    int N, K, YOSEPH[5000] = {0};
    scanf("%d %d", &N, &K);

    for (int i = 1; i <= N; i++) // 편의성을 위해 0의 칸을 비움
    {
        YOSEPH[i] = 1; // key값이 있는 곳에 1로 표시
    }

    //여기까지가 데이터 입력 과정

    printf("<");

    int cnt = 0; // 출력해야 하는 횟수(N과 동일해야 종료)

    int g = 1, Kcnt = 0; // 인덱스의 위치 g와 K번 돌아갔는지 확인을 위한 Kcnt
    while (cnt < N)
    {
        if (g > N) // 인덱스의 범위 조건 검사
        {
            g -= N;//범위 초과시 시작 위치로 돌아감
        }

        if (Kcnt == K - 1)
        { // 출력해야하는 경우
            if (YOSEPH[g] != 0)//도착한 인덱스가 비어있지 않은 경우
            {
                printf("%d", g);
                YOSEPH[g] = 0; // 이제 그 인덱스를 비워줌
                Kcnt = 0;      // 초기화
                cnt++;
                g++;
                if (cnt == N)
                { // 종료조건일 때
                    printf(">");
                }
                else
                { // 조건은 맞지만 종료조건은 아닌 경우
                    printf(", ");
                }
            }
            else{
                g++;
            }
        }

        else
        { // 출력 위치를 찾는 과정
            if (YOSEPH[g] == 1)
            { // 그 수가 존재할 경우
                Kcnt++;

            }
            g++;
        }
    }

    return 0;
}