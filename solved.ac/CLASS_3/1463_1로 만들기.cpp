#include <iostream>
#include <climits>

using namespace std;

const int MAX = 1e6 + 1;

int N;
int dp[MAX];

int main(int argc, char const *argv[])
{
    fill_n(&dp[0], MAX, INT_MAX);

    cin >> N;

    dp[1] = 0;

    for (int i = 2; i <= N; i++)
    {
        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + 1);
        
        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3] + 1);
        
        dp[i] = min(dp[i], dp[i - 1] + 1);
    }

    cout << dp[N] << "\n";

    return 0;
}
