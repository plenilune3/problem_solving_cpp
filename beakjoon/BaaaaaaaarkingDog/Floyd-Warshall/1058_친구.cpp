#include <iostream>
#include <climits>

using namespace std;

const int MAX = 51;

int N;
char adj[MAX][MAX];
int dp[MAX][MAX];

int main(int argc, char const *argv[])
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> adj[i];

        for (int j = 0; j < N; j++)
            dp[i][j] = adj[i][j] == 'Y' ? 1 : MAX * MAX;
    }

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (dp[i][j] > dp[i][k] + dp[k][j])
                    dp[i][j] = dp[i][k] + dp[k][j];
   
    int answer = 0;

    for (int i = 0; i < N; i++)
    {
        int cnt = 0;

        for (int j = 0; j < N; j++)
        {
            if (i == j)
                continue;

            if (dp[i][j] <= 2)
                cnt += 1;
        }
        
        answer = max(answer, cnt);
    }

    cout << answer << "\n";

    return 0;
}

