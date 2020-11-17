#include <iostream>

using namespace std;

const int MAX = 101;

int N, K, dp[100001];
int W[MAX], V[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        cin >> W[i] >> V[i];
    
    for (int i = 1; i <= N; i++)
    {
        int weight = W[i], value = V[i];

        for (int j = K; j >= 0; j--)
            if (weight <= j)
                dp[j] = max(dp[j], dp[j - weight] + value);
    }
    
    cout << dp[K] << "\n";

    return 0;
}
