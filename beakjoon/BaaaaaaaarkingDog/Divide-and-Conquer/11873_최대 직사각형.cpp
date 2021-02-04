#include <iostream>

using namespace std;

const int MAX = 1e3 + 1;

int N, M;
int dp[MAX][MAX];

int rectangle_(int k, int left, int right);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (true)
    {
        int answer = 0;

        cin >> N >> M;

        if (N == 0 && M == 0) break;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> dp[i][j];
        
        for (int i = 1; i < N; i++)
            for (int j = 0; j < M; j++)
                dp[i][j] = dp[i][j] == 1 ? dp[i - 1][j] + dp[i][j] : dp[i][j];
        
        for (int i = 0; i < N; i++)
            answer = max(answer, rectangle_(i, 0, M - 1));
        
        cout << answer << "\n";
    }

    return 0;
}

int rectangle_(int k, int left, int right)
{
    if (left == right)
        return dp[k][left];
    
    int mid = (left + right) / 2;
    int ret = max(rectangle_(k, left, mid), rectangle_(k, mid + 1, right));

    int l = mid, r = mid;
    int min_height = min(dp[k][l], dp[k][r]);
    ret = max(ret, min_height * (r - l + 1));

    while (l > left || r < right)
    {
        if (r < right && (l == left || dp[k][l - 1] < dp[k][r + 1]))
            min_height = min(min_height, dp[k][++r]);
        else
            min_height = min(min_height, dp[k][--l]);

        ret = max(ret, min_height * (r - l + 1));
    }

    return ret;
}
