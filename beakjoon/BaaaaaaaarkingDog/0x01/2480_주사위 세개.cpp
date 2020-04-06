#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int a, b, c, price, temp;

    scanf("%d %d %d", &a, &b, &c);

    if (a < b)
    {
        temp = a; a = b; b = temp;
    }
    if (b < c)
    {
        temp = b; b = c; c = temp;
    }
    if (a < b)
    {
        temp = a; a = b; b = temp;
    }

    if (a == b || a == c)
    {
        if (b == c)
            price = 10000 + c * 1000;
        else
            price = 1000 + a * 100;
    }
    else if (b == c)
        price = 1000 + b * 100;
    else
        price = a * 100;

    printf("%d\n", price);

    return 0;
}
