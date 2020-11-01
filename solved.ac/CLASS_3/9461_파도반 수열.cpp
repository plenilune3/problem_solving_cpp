#include <iostream>

using namespace std;

const int MAX = 101;

long long dp[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T; cin >> T;

    while (T--)
    {
        fill_n(&dp[0], MAX, 0);

        int N; cin >> N;

        dp[1] = dp[2] = dp[3] = 1;

        for (int i = 4; i <= N; i++)
            dp[i] = dp[i - 2] + dp[i - 3];
        
        cout << dp[N] << "\n";
    }

    return 0;
}
