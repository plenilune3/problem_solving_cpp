#include <iostream>

using namespace std;

const int MAX = 401;

bool dp[MAX][MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int N, K, S;
    cin >> N >> K;

    while (K--)
    {
        int a, b;
        cin >> a >> b;

        dp[a][b] = true;
    }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                dp[i][j] |= dp[i][k] & dp[k][j];

    cin >> S;

    while (S--)
    {
        int a, b;
        cin >> a >> b;

        if (dp[a][b])
            cout << -1 << "\n";
        else if (dp[b][a])
            cout << 1 << "\n";
        else
            cout << 0 << "\n"; 
    }

    return 0;
}

