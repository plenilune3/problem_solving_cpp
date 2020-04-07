#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
    int T, A, B;

    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", A+B);
    }

    return 0;
}
