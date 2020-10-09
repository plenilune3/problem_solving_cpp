#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e5 + 1;

int N, M;
int dp[MAX];
vector< vector<int> > node(MAX);

void dfs(int x);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        int u; cin >> u;

        if (u == -1) continue;

        node[u].push_back(i);
    }

    while (M--)
    {
        int u, w; cin >> u >> w;

        dp[u] += w;
    }

    dfs(1);

    for (int i = 1; i <= N; i++)
        cout << dp[i] << " ";
    cout << "\n";

    return 0;
}

void dfs(int x)
{
    for (vector<int>::iterator iter = node[x].begin(); iter != node[x].end(); iter++)
    {
        int nx = (*iter);

        dp[nx] += dp[x];

        dfs(nx);
    }
}

