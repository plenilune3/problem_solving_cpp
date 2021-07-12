#include <iostream>

using namespace std;

const int MAX = 1e4 + 1;

int N;
double A[MAX], dp[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> A[i];
    
    double answer = 0;

    for (int i = 1; i <= N; i++)
    {
        dp[i] = max(A[i], dp[i-1] * A[i]);

        answer = max(answer, dp[i]);
    }
    
    cout << fixed;
    cout.precision(3);

    cout << answer << "\n";

    return 0;
}
