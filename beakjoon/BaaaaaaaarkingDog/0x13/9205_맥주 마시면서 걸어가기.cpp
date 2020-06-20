#include <iostream>

using namespace std;

const int MAX = 103;

int N;
int dp[MAX][MAX];
pair<int, int> node[MAX];

int get_distance(int a, int b, int c, int d)
{
    int result = 0;

    result += (a > c) ? a - c : c - a;
    result += (b > d) ? b - d : d - b;

    return result;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        cin >> N;

        for (int i = 1; i <= N + 2; i++)
            cin >> node[i].first >> node[i].second;

        for (int i = 1; i <= N + 2; i++)
            for (int j = 1; j <= N + 2; j++)
                dp[i][j] = (i == j) ? 0 : 1000 * MAX + 1;
        
        for (int i = 1; i <= N + 2; i++)
            for (int j = 1; j <= N + 2; j++)
            {
                int distance = get_distance(node[i].first, node[i].second, node[j].first, node[j].second);

                dp[i][j] = (distance <= 1000) ? distance : dp[i][j];
            }
        
        for (int k = 1; k <= N + 2; k++)
            for (int i = 1; i <= N + 2; i++)
                for (int j = 1; j <= N + 2; j++)
                    if (dp[i][j] > dp[i][k] + dp[k][j])
                        dp[i][j] = dp[i][k] + dp[k][j];
        
        if (dp[1][N + 2] != 1000 * MAX + 1)
            cout << "happy\n";
        else
            cout << "sad\n";
    }

    return 0;
}
