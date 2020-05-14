#include <iostream>

using namespace std;

const int MAX = 34;

int N;
bool h[MAX][MAX];
long long dp[3][MAX][MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> h[i][j];
    
    dp[0][1][2] = 1;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            if (h[i][j + 1] == false)
                dp[0][i][j + 1] += dp[0][i][j] + dp[2][i][j];
            if (h[i + 1][j] == false)
                dp[1][i + 1][j] += dp[1][i][j] + dp[2][i][j];
            if (h[i + 1][j + 1] == false && h[i][j + 1] == false && h[i + 1][j] == false)
                dp[2][i + 1][j + 1] += dp[0][i][j] + dp[1][i][j] + dp[2][i][j];
        }
    
    cout << dp[0][N][N] + dp[1][N][N] + dp[2][N][N] << "\n";

    return 0;
}
