#include <iostream>
#include <vector>

using namespace std;

const int MAX = 101;

int N, M;
vector< vector<int> > node(MAX);
bool visited[MAX];

int dfs(int u);

int main(int argc, char const *argv[])
{
    cin >> N >> M;

    while (M--)
    {
        int u, v; cin >> u >> v;

        node[u].push_back(v);
        node[v].push_back(u);
    }

    cout << dfs(1) - 1 << "\n";
    
    return 0;
}

int dfs(int u)
{
    visited[u] = true;

    int ret = 1;

    for (vector<int>::iterator i = node[u].begin(); i != node[u].end(); i++)
    {
        int v = (*i);

        if (visited[v]) continue;

        ret += dfs(v);
    }

    return ret;
}
