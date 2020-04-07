#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
    int Y = 0, M = 0, temp;
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &temp);

        Y += ((temp / 30) + 1) * 10;
        M += ((temp / 60) + 1) * 15;
    }
    
    if (Y == M) printf("Y M %d\n", Y);
    else if (Y < M) printf("Y %d\n", Y);
    else printf("M %d\n", M);

    return 0;
}
