#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, K, S, Y, count = 0;
    int room[6][2];

    scanf("%d %d", &N, &K);
    fill(&room[0][0], &room[6][2], 0);

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &S, &Y);
        room[Y-1][S] += 1;
    }

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            count += (room[i][j] / K);
            if (room[i][j] % K)
                count += 1;
        }
    }

    // for (int i = 0; i < 6; i++)
    // {   printf("[ ");
    //     for (int j = 0; j < 2; j++)
    //     {
    //         printf("%d ", room[i][j]);
    //     }
 
    //     printf("]\n");
    // }

    printf("%d\n", count);

    return 0;
}

