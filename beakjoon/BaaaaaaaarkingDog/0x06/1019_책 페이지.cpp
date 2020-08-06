#include <iostream>

using namespace std;

long long digits[10];

void calc(long long N, long long digit)
{
    while (N > 0)
    {
        digits[N % 10] += digit;
        N /= 10;
    }
}

void solve(long long A, long long B, long long digit)
{
    while (A % 10 != 0 && A <= B)
    {
        calc(A, digit);
        A++;
    }
    
    if (A > B)
        return;
    
    while (B % 10 != 9 && B >= A)
    {
        calc(B, digit);
        B--;
    }

    long long cnt = (B / 10 - A / 10 + 1);

    for (int i = 0; i < 10; i++)
        digits[i] += cnt * digit;
    
    solve(A / 10, B / 10, digit * 10);
}

int main(int argc, char const *argv[])
{
    long long N;
    cin >> N;

    solve(1, N, 1);

    for (int i = 0 ; i < 10; i++)
        cout << digits[i] << " ";

    return 0;
}
