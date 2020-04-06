#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int a, b, c, d;
    int sum_abcd;

    for (int i=0; i < 3; i++)
    {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        sum_abcd = a + b + c + d;
        if (sum_abcd == 4)
            printf("E\n");
        else
            printf("%c\n", 'D' - sum_abcd);
    }

    return 0;
}
