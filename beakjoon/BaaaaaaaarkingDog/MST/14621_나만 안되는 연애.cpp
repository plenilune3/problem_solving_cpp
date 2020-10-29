#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class union_find
{
private:
    vector<int> parent;
public:
    void make_set(int N)
    {
        parent = vector<int> (N + 1, -1);
    }

    int find(int u)
    {
        if (parent[u] < 0) return u;

        int v = find(parent[u]);
        parent[u] = v;

        return v;
    }

    void merge(int u, int v)
    {
        u = find(u), v = find(v);

        if (u == v) return;

        if (parent[u] > parent[v]) swap(u, v);

        parent[u] += parent[v];
        parent[v] = u;
    }
};

const int MAX_N = 1e3 + 1;
const int MAX_M = 1e4 + 1;

struct edge
{
    int u, v, w;

    bool operator< (const edge &e) const
    {
        return w < e.w;
    }
};

int N, M;
char gender[MAX_N];
edge edges[MAX_M];

edge make_edge(int u, int v, int w);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> gender[i];
    
    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        if (gender[u] != gender[v])
            edges[i] = make_edge(u, v, w);
    }

    sort(edges, edges + M);

    union_find *g = new union_find();
    g->make_set(N);
    int count_edge = 0, sum_weight = 0;

    for (int i = 0; i < M; i++)
    {
        if (count_edge == N - 1)
            break;
        
        if (g->find(edges[i].u) != g->find(edges[i].v))
        {
            g->merge(edges[i].u, edges[i].v);
            count_edge += 1;
            sum_weight += edges[i].w;
        }
    }

    delete g;

    if (count_edge == N - 1)
        cout << sum_weight << "\n";
    else
        cout << -1 << "\n";

    return 0;
}

edge make_edge(int u, int v, int w)
{
    edge e = { u, v, w };
    return e;
}
