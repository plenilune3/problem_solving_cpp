#include <iostream>

using namespace std;

const int MAX = 301;

int N;
int score[MAX];
int dp[MAX][3];

int main(int argc, char const *argv[])
{
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> score[i];
    
    dp[1][1] = score[1];
    
    for (int i = 2; i <= N; i++)
    {
        dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + score[i];
        dp[i][2] = dp[i - 1][1] + score[i];
    }

    int answer = 0;

    for (int i = 1; i <= 2; i++)
        answer = max(answer, dp[N][i]);
    
    cout << answer << "\n";

    return 0;
}
