#include <iostream>

using namespace std;

const int MAX = 41;

int dp[MAX][MAX];

int lower_bound_(int table[MAX], int target, int length);

int main(int argc, char const *argv[])
{
    string A, B, answer = "";
    cin >> A >> B;

    A = "0" + A, B = "0" + B;
    int length_A = (int) A.size(), length_B = (int) B.size();

    for (int i = 1; i < length_A; i++)
    {
        for (int j = 1; j < length_B; j++)
            if (A[i] == B[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }

    int i = length_A - 1, j = length_B - 1;

    while (dp[i][j] != 0)
    {
        if (dp[i][j] == dp[i][j - 1])
            j--;
        
        else if (dp[i][j] == dp[i - 1][j])
            i--;
        
        else if (dp[i][j] - 1 == dp[i - 1][j - 1])
        {
            answer = A[i] + answer;
            i--, j--;
        }
    }

    cout << answer << "\n";

    return 0;
}