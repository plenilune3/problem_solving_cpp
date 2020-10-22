#include <iostream>

using namespace std;

int gcd(int a, int b);
int lcm(int a, int b);

int main(int argc, char const *argv[])
{
    int N, M;
    cin >> N >> M;

    cout << gcd(N, M) << "\n";
    cout << lcm(N, M) << "\n";

    return 0;
}

int gcd(int a, int b)
{
    if (a > b) swap(a, b);

    while (b)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
