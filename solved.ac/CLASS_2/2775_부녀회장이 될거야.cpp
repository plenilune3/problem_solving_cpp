#include <iostream>

using namespace std;

const int MAX = 15;

int dp[MAX][MAX];

int main(int argc, char const *argv[])
{

    for (int i = 1; i <= 14; i++)
        dp[0][i] = i;
    
    for (int i = 1; i <= 14; i++)
        for (int j = 1; j <= 14; j++)
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j];

    int T; cin >> T; 

    while (T--)
    {
        int N, K;
        cin >> N >> K;
        cout << dp[N][K] << "\n";
    }

    return 0;
}
