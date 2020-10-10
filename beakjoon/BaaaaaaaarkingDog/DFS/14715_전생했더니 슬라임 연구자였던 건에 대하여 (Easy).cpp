#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int MAX = 1e6 + 1;

int K, answer;
int dp[MAX];
bool is_prime[MAX];

void find_prime();
int dfs(int x);

int main(int argc, char const *argv[])
{
    find_prime();

    cin >> K;

    cout << dfs(K) << "\n";

    return 0;
}

int dfs(int x)
{
    if (dp[x] || is_prime[x]) return dp[x];

    int k = x / 2;
    dp[x] = MAX;

    for (int a = 2; a < k + 1; a++)
        if (x % a == 0)
        {
            int b = x / a;
            int max_t = max(dfs(a) + 1, dfs(b) + 1);
            dp[x] = min(dp[x], max_t);
        }

    return dp[x];
}

void find_prime()
{
    fill_n(&is_prime[0], MAX, true);

    is_prime[1] = false;
    int k = sqrt(MAX) + 1;

    for (int i = 2; i < k; i++)
        if (is_prime[i])
            for (int j = i * i; j < MAX; j += i)
                is_prime[j] = false;
}