#include <iostream>

using namespace std;

const int MAX = 101;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int N, M;
    int dp[MAX][MAX];

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            dp[i][j] = (i == j) ? 0 : 101;
    
    for (int i = 1; i <= M; i++)
    {
        int a, b;
        cin >> a >> b;
        dp[a][b] = 1;
        dp[b][a] = 1;
    }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (dp[i][j] > dp[i][k] + dp[k][j])
                    dp[i][j] = dp[i][k] + dp[k][j];

    int result, sum_min = MAX * MAX;

    for (int i = 1; i <= N; i++)
    {
        int temp = 0;

        for (int j = 1; j <= N; j++)
            temp += dp[i][j];
        
        if (temp < sum_min)
            sum_min = temp, result = i;
    }

    cout << result << "\n";

    return 0;
}
