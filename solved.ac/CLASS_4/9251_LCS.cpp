#include <iostream>

using namespace std;

const int MAX = 1e3 + 1;

int answer;
int dp[MAX][MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string A, B; cin >> A >> B;
    A = "0" + A, B = "0" + B;
    int length_A = (int) A.size(), length_B = (int) B.size();

    for (int i = 1; i < length_A; i++)
        for (int j = 1; j < length_B; j++)
            if (A[i] == B[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    
    int i = length_A - 1, j = length_B - 1;

    while (dp[i][j] != 0)
    {
        if (dp[i][j] == dp[i - 1][j]) i--;
        else if (dp[i][j] == dp[i][j - 1]) j--;
        else if (dp[i][j] - 1 == dp[i - 1][j - 1]) 
        {
            answer += 1;
            i--, j--;
        }
    }

    cout << answer << "\n";
    
    return 0;
}

