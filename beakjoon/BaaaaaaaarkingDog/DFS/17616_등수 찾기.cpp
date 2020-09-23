#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e5 + 1;

int N, M, X;
vector< vector<int> > node(MAX);
vector< vector<int> > node_reverse(MAX);
bool visited[2][MAX];

int find_rank(int n, bool is_reverse, vector< vector<int> > &node);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> X;

    for (int i = 0; i < M; i++)
    {
        int u, v; cin >> u >> v;
        node[u].push_back(v);
        node_reverse[v].push_back(u);
    }

    int right = find_rank(X, false, node) - 1;
    int left = find_rank(X, true, node_reverse) - 1;

    cout << 1 + left << " " << N - right << "\n";

    return 0;
}

int find_rank(int n, bool is_reverse, vector< vector<int> > &node)
{
    visited[is_reverse][n] = true;
    int ret = 1;

    for (vector<int>::iterator iter = node[n].begin(); iter != node[n].end(); iter++)
    {
        int nn = (*iter);

        if (visited[is_reverse][nn])
            continue;
        
        ret += find_rank(nn, is_reverse, node);
    }

    return ret;
}
