#include <iostream>

using namespace std;

const int MAX = 101;

int N, M, dp[MAX][MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            dp[i][j] = (i == j) ? 0 : 1e9;

    while (M--)
    {
        int x, y, w; cin >> x >> y >> w;
        dp[x][y] = min(dp[x][y], w);
    }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (dp[i][j] > dp[i][k] + dp[k][j])
                    dp[i][j] = dp[i][k] + dp[k][j];
    
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            if (dp[i][j] == 1e9) cout << 0 << " ";
            else cout << dp[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
