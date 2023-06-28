#include <stdio.h>
#include <string.h>

int main()
{
    int n, cnt = 0;
    scanf("%d", &n);

    char word[100][100];

    int t = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%s", word[i]);

        int TRFA = 0, len;
        len = strlen(word[i]);
        /* 목표 타겟에서 한칸 넘어에서 다시 재등장하는지만 파악하면 된다 */
        for (t = 0; t < len - 2; t++)
        {
            for (int j = t + 2; j < len; j++)
            {
                if (word[i][t] == word[i][j] && word[i][j] != word[i][j-1])
                {
                    TRFA = 1;

                    break;
                }
            }
        }
        if (TRFA == 0)
            cnt++;
    }

    printf("%d", cnt);

    return 0;
}