#include <iostream>

using namespace std;

const int MAX = 5001;

int N;
int dp[MAX];

int main(int argc, char const *argv[])
{
    cin >> N;

    dp[3] = dp[5] = 1;

    for (int i = 6; i <= N; i++)
    {
        if (dp[i - 5])
        {
            dp[i] = dp[i - 5] + 1;
            continue;
        }

        if (dp[i - 3])
        {
            dp[i] = dp[i - 3] + 1;
            continue;
        }
    }

    if (dp[N])
        cout << dp[N] << "\n";
    else
        cout << -1 << "\n";

    return 0;
}
