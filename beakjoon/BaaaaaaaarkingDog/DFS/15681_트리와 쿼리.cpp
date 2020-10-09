#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e5 + 1;

int N, R, Q;
int dp[MAX];
vector< vector<int> > node(MAX);
bool visited[MAX];

int count_subtree_nodes(int x);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> R >> Q;

    for (int i = 0; i < N - 1; i++)
    {
        int u, v; cin >> u >> v;

        node[u].push_back(v);
        node[v].push_back(u);
    }

    count_subtree_nodes(R);

    while (Q--)
    {
        int query; cin >> query;
        
        cout << count_subtree_nodes(query) << "\n";
    }

    return 0;
}

int count_subtree_nodes(int x)
{
    if (dp[x])
        return dp[x];
    
    dp[x] = 1;
    visited[x] = true;

    for (vector<int>::iterator iter = node[x].begin(); iter != node[x].end(); iter++)
    {
        int nx = (*iter);

        if (visited[nx]) continue;

        dp[x] += count_subtree_nodes(nx);
    }

    return dp[x];
}