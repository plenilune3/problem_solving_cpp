#include <iostream>

using namespace std;

const int MAX = 501;

int N, M;
bool dp[MAX][MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int u, v; cin >> u >> v;
        dp[u][v] = true;
    }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (dp[i][k] && dp[k][j])
                    dp[i][j] = true;
    
    int answer = 0;

    for (int k = 1; k <= N; k++)
    {
        int cnt = 0;

        for (int i = 1; i <= N; i++)
            cnt += dp[k][i];
        
        for (int i = 1; i <= N; i++)
            cnt += dp[i][k];
        
        if (cnt == N - 1)
            answer += 1;
    }

    cout << answer << "\n";

    return 0;
}
