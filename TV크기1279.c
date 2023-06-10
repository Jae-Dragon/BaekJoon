#include <stdio.h>
#include <math.h>

int main()
{
    int D, H, W;
    scanf("%d %d %d", &D, &H, &W);

    int DD, HHWW;
    double N;

    DD = pow(D,2);
    HHWW = pow(H,2) + pow(W,2);

    //이러면 N제곱 * HHWW == DD이므로 DD/HHWW를 해준 뒤에 sqrt N을 해준다
    N = sqrt((double)DD/(double)HHWW);//double을 안붙여주면 DD가 HHWW보다 작을 때 값이 0이 됨

    double h, w;
    h = N * H;
    w = N * W;

    printf("%d %d", (int)h, (int)w);

    return 0;
}