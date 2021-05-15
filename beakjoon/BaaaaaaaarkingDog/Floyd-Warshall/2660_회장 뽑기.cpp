#include <iostream>
#include <vector>

using namespace std;

const int MAX = 51;

int N, dp[MAX][MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            dp[i][j] = (i == j) ? 0 : MAX * MAX;

    while (true)
    {
        int u, v; cin >> u >> v;

        if (u == -1 && v == -1)
            break;
        
        dp[u][v] = dp[v][u] = 1;
    }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (dp[i][j] > dp[i][k] + dp[k][j])
                    dp[i][j] = dp[i][k] + dp[k][j];
    
    int score = MAX * MAX;

    for (int i = 1; i <= N; i++)
    {
        int temp = 0;

        for (int j = 1; j <= N; j++)
            temp = max(temp, dp[i][j]);
        
        score = min(score, temp);
    }

    vector<int> answer;

    for (int i = 1; i <= N; i++)
    {
        int temp = 0;

        for (int j = 1; j <= N; j++)
            temp = max(temp, dp[i][j]);
        
        if (temp == score)
            answer.push_back(i);
    }

    cout << score << " " << answer.size() << "\n";

    for (vector<int>::iterator i = answer.begin(); i != answer.end(); i++)
        cout << (*i) << " ";
    cout << "\n";


    return 0;
}
