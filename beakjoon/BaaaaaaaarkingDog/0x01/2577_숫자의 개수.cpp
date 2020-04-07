#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
    int a, b, c, result, number;
    int number_count[10] = {0};

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    result = a * b * c;

    while (result > 0)
    {
        number_count[result%10] += 1;
        result = result / 10;
    }

    for (int i = 0; i < 10; i++)
        printf("%d\n", number_count[i]);

    return 0;
}
