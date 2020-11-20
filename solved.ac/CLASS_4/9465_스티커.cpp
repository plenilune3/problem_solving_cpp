#include <iostream>

using namespace std;

const int MAX = 1e5 + 3;

int dp[2][MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T; cin >> T;

    while (T--)
    {
        int N; cin >> N;

        for (int i = 0; i < 2; i++)
            for (int j = 2; j < N + 2; j++)
                cin >> dp[i][j];
        
        for (int j = 2; j < N + 2; j++)
            for (int i = 0; i < 2; i++)
                dp[i][j] = max(dp[(i + 1) % 2][j - 1], dp[(i + 1) % 2][j - 2]) + dp[i][j];
        
        cout << max(dp[0][N + 1], dp[1][N + 1]) << "\n";
    }

    return 0;
}
