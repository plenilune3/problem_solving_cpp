#include <iostream>

using namespace std;

const int MAX = 101;

int N, M, K;
int dp[MAX][MAX];
int f[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        cin >> N >> M;

        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (i == j)
                    dp[i][j] = 0;
                else
                    dp[i][j] = 1000 * 100 + 1;

        for (int i = 0; i < M; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            dp[u][v] = w;
            dp[v][u] = w;
        }

        cin >> K;

        for (int i = 0; i < K; i++)
            cin >> f[i];

        for (int k = 1; k <= N; k++)
            for (int i = 1; i <= N; i++)
                for (int j = 1; j <= N; j++)
                    if (dp[i][j] > dp[i][k] + dp[k][j])
                        dp[i][j] = dp[i][k] + dp[k][j];
        
        int min_distance = 1000 * 100 + 1;
        int answer;

        for (int i = 1; i <= N; i++)
        {
            int sum_distance = 0;

            for (int j = 0; j < K; j++)
                sum_distance += dp[f[j]][i];
            
            if (sum_distance < min_distance)
            {
                min_distance = sum_distance;
                answer = i;
            }
        }

        cout << answer << "\n";
    }

    return 0;
}
