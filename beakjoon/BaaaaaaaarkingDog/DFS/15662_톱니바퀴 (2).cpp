#include <cstdio>
#include <algorithm>

using namespace std;

int const MAX = 1001;

int T, K;
int gear[MAX][8];

void rotate(int gear[8], int d)
{
    int gear_copy[8];

    for (int i = 0; i < 8; i++)
        if (d == 1)
            gear_copy[(i + 1) % 8] = gear[i];
        else
            gear_copy[i] = gear[(i + 1) % 8];
    
    copy(&gear_copy[0], &gear_copy[0] + 8, &gear[0]);
}

int main(int argc, char const *argv[])
{
    scanf("%d", &T);

    for (int t = 1; t <= T; t++)
        for (int i = 0; i < 8; i++)
            scanf("%1d", &gear[t][i]);
    
    scanf("%d", &K);

    while (K--)
    {
        int num, direction;
        scanf("%d %d", &num, &direction);

        int d[T + 1];
        fill_n(&d[0], T + 1, 0);
        d[num] = direction;

        for (int i = num; i < T; i++)
            if (gear[i][2] != gear[i + 1][6])
                d[i + 1] = -d[i];
            else
                break;

        for (int i = num; i > 1; i--)
            if (gear[i][6] != gear[i - 1][2])
                d[i - 1] = -d[i];
            else
                break;
        
        for (int i = 1; i <= T; i++)
            if (d[i])
                rotate(gear[i], d[i]);
    }

    int answer = 0;

    for (int i = 1; i <= T; i++)
        if (gear[i][0])
            answer += 1;
    
    printf("%d\n", answer);

    return 0;
}
