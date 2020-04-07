#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
    long long a, b, temp;
    int diff = 0;

    scanf("%lld %lld", &a, &b);

    if (a > b)
    {
        temp = a; a = b; b = temp;
    }

    if (a == b)
        printf("0\n");
    else
    {
        diff = b - a - 1;
        printf("%lld\n", diff);

        for (int i = 1; i < diff + 1; i++)
            printf("%lld ", a + i);
    }
    
    return 0;
}
