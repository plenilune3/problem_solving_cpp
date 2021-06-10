#include <iostream>

using namespace std;

const int MAX_V = 401;
const int MAX_D = MAX_V * 2 * 10001;

int V, E, dp[MAX_V][MAX_V], answer = MAX_D;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> V >> E;

    fill_n(&dp[0][0], MAX_V * MAX_V, MAX_D);

    while (E--)
    {
        int a, b, c; cin >> a >> b >> c;
        dp[a][b] = c;
    }

    for (int k = 1; k <= V; k++)
        for (int i = 1; i <= V; i++)
            for (int j = 1; j <= V; j++)
                if (dp[i][j] > dp[i][k] + dp[k][j])
                    dp[i][j] = dp[i][k] + dp[k][j];

    for (int u = 1; u <= V; u++)
        for (int v = 1; v <= V; v++)
        {
            if (u == v)
                continue;
            
            if (dp[u][v] == MAX_D || dp[v][u] == MAX_D)
                continue;
            
            answer = min(answer, dp[u][v] + dp[v][u]);
        }
    
    if (answer != MAX_D)
        cout << answer << "\n";
    else
        cout << -1 << "\n";

    return 0;
}
