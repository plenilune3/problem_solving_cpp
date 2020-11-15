#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e5 + 1;

struct edge
{
    int v, w;
};

int N;
bool visited[MAX];
vector< vector<edge> > node(MAX);

pair<int, int> dfs(int w, int u);
edge make_edge(int v, int w);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int u; cin >> u;

        while (true)
        {
            int v; cin >> v;

            if (v == -1) break;

            int w; cin >> w;

            node[u].push_back(make_edge(v, w));
            // node[v].push_back(make_edge(u, w));
        }
    }

    pair<int, int> A = dfs(0, 1);

    fill_n(&visited[0], MAX, false);
    
    pair<int, int> B = dfs(0, A.second);

    cout << B.first << "\n";

    return 0;
}

pair<int, int> dfs(int w, int u)
{
    visited[u] = true;
    pair<int, int> ret = make_pair(w, u);

    for (vector<edge>::iterator i = node[u].begin(); i != node[u].end(); i++)
    {
        int nv = (*i).v, nw = (*i).w;

        if (visited[nv]) continue;

        pair<int, int> c = dfs(nw + w, nv);

        if (ret.first < c.first)
            ret = c;
    }

    return ret;
}

edge make_edge(int v, int w)
{
    edge e = { v, w };
    return e;
}