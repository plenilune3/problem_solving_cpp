#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e5 + 1;

int N, p[MAX];
bool visited[MAX];
vector< vector<int> > node(MAX);

void dfs(int d, int v);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int u, v; cin >> u >> v;

        node[u].push_back(v);
        node[v].push_back(u);
    }

    dfs(0, 1);

    for (int u = 2; u <= N; u++)
        cout << p[u] << "\n";

    return 0;
}

void dfs(int d, int v)
{
    visited[v] = true;

    for (vector<int>::iterator i = node[v].begin(); i != node[v].end(); i++)
    {
        int nv = (*i);

        if (visited[nv]) continue;

        p[nv] = v;
        dfs(d + 1, nv);
    }
}
