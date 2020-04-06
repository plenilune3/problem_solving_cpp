#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, X;
    int temp;

    scanf("%d %d", &N, &X);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &temp);

        if (temp < X)
            printf("%d ", temp);
    }

    return 0;
}
