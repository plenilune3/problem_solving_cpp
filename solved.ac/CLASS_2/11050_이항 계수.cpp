#include <iostream>

using namespace std;

const int MAX = 11;

int N, K;
int dp[MAX][MAX];

int main(int argc, char const *argv[])
{
    cin >> N >> K;

    for (int n = 1; n <= N; n++)
        for (int k = 0; k <= n; k++)
        {
            if (k == 0 || k == n)
                dp[n][k] = 1;
            else if (k == 1)
                dp[n][k] = n;
            else
                dp[n][k] = dp[n - 1][k - 1] + dp[n - 1][k];
        }
    
    cout << dp[N][K] << "\n";

    return 0;
}
