#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 4e4 + 1;

int N, M, max_level = (int) floor(log2(MAX));
int depth[MAX], parent[MAX][21], dist[MAX];
bool visited[MAX];
vector< vector< pair<int, int> > > node(MAX);

void dfs(int d, int v);
void fill_parent();
int find_lca(int x, int y);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        node[u].push_back(make_pair(v, w));
        node[v].push_back(make_pair(u, w));
    }

    dfs(0, 1);
    fill_parent();

    cin >> M;

    while (M--)
    {
        int u, v;
        cin >> u >> v;
        int distance = dist[u] + dist[v] - dist[find_lca(u, v)] * 2;
        cout << distance << "\n";
    }

    return 0;
}

void dfs(int d, int v)
{
    visited[v] = true;
    depth[v] = d;

    for (vector< pair<int, int> >::iterator iter = node[v].begin(); iter != node[v].end(); iter++)
    {
        if (visited[(*iter).first])
            continue;
        
        dist[(*iter).first] = dist[v] + (*iter).second;
        parent[(*iter).first][0] = v;
        dfs(d + 1, (*iter).first);
    }
}

void fill_parent()
{
    for (int j = 1; j <= max_level; j++)
        for (int i = 1; i <= N; i++)
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
}

int find_lca(int x, int y)
{
    if (depth[x] > depth[y]) swap(x, y);

    for (int i = max_level; i >= 0; i--)
        if (depth[y] - depth[x] >= (1 << i))
            y = parent[y][i];

    if (x == y) return x;

    for (int i = max_level; i >= 0; i--)
        if (parent[x][i] != parent[y][i])
            x = parent[x][i], y = parent[y][i];
    
    return parent[x][0];
}