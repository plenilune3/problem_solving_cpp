#include <iostream>

using namespace std;

const int MAX = 30;

int N, K;
char str[31];
bool dp[31][31][31][436];

bool dfs(int depth, int a, int b, int p);

int main(int argc, char const *argv[])
{
    cin >> N >> K;

    if (dfs(0, 0, 0, 0))
        cout << str << "\n";
    else
        cout << -1 << "\n";

    return 0;
}

bool dfs(int depth, int a, int b, int p)
{
    if (depth == N)
    {
        if (p == K) return true;
        else return false;
    }

    if (dp[depth][a][b][p]) return false;

    dp[depth][a][b][p] = true;

    str[depth] = 'A';
    if (dfs(depth + 1, a + 1, b, p)) return true;

    str[depth] = 'B';
    if (dfs(depth + 1, a, b + 1, p + a)) return true;

    str[depth] = 'C';
    if (dfs(depth + 1, a, b, p + a + b)) return true;

    return false;
}