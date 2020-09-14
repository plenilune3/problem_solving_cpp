#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 1e5 + 1;

int N, M;
int depth[MAX], parent[MAX][21];
int max_level;
bool visited[MAX];
vector< vector<int> > node(MAX);

void dfs(int depth, int v);
void fill_parent();
int find_lca(int x, int y);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    max_level = (int) floor(log2(MAX));

    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }

    dfs(0, 1);
    fill_parent();

    cin >> M;

    while (M--)
    {
        int u, v;
        cin >> u >> v;
        cout << find_lca(u, v) << "\n";
    }

    return 0;
}

void dfs(int d, int v)
{
    visited[v] = true;
    depth[v] = d;

    for (vector<int>::iterator iter = node[v].begin(); iter != node[v].end(); iter++)
    {
        if (visited[(*iter)])
            continue;
        
        parent[(*iter)][0] = v;
        dfs(d + 1, (*iter));
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
    if (depth[x] > depth[y])
        swap(x, y);
    
    for (int i = max_level; i >= 0; i--)
        if (depth[y] - depth[x] >= (1 << i))
            y = parent[y][i];
    
    if (x == y) return x;

    for (int i = max_level; i >= 0; i--)
        if (parent[x][i] != parent[y][i])
            x = parent[x][i], y = parent[y][i];
    
    return parent[x][0];
}
