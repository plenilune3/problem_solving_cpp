#include <iostream>

using namespace std;

void hanoi(int a, int b, int n);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int N;
    cin >> N;

    cout << (1 << N) - 1 << "\n";
    hanoi(1, 3, N);
    
    return 0;
}

void hanoi(int a, int b, int n)
{
    if (n == 1)
    {
        cout << a << " " << b << "\n";
        return;
    }

    int next = 6 - (a + b);

    hanoi(a, next, n - 1);
    cout << a << " " << b << "\n";
    hanoi(next, b, n - 1);
}