#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e5 + 1;

struct edge
{
    int p, q, r;

    bool operator<(const edge &e)
    {
        return r > e.r;
    }
};

struct query
{
    int k, v, idx;

    bool operator< (const query &q)
    {
        return k > q.k;
    }
};

int N, Q;
int parent[MAX], answer[MAX];
edge edges[MAX];
query queries[MAX];

int find_(int u);
void union_(int u, int v);
int lower_bound_(int x);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> Q;

    for (int i = 0; i < N - 1; i++)
        cin >> edges[i].p >> edges[i].q >> edges[i].r;
    
    for (int i = 0; i < Q; i++)
    {
        cin >> queries[i].k >> queries[i].v;
        queries[i].idx = i;
    }

    for (int i = 0; i <= N; i++)
        parent[i] = -1;

    sort(edges, edges + (N - 1));
    sort(queries, queries + Q);

    int j = 0;

    for (int i = 0; i < Q; i++)
    {
        int k = queries[i].k, v = queries[i].v;
        int idx = queries[i].idx;

        for (; j < N - 1; j++)
        {
            if (edges[j].r >= k)
                union_(edges[j].p, edges[j].q);
            else
                break;
        }

        answer[idx] = -parent[find_(v)] - 1;
    }

    for (int i = 0; i < Q; i++)
        cout << answer[i] << "\n";

    return 0;
}

int find_(int u)
{
    if (parent[u] < 0)
        return u;
    else
    {
        int v = find_(parent[u]);
        return parent[u] = v;
    }
}

void union_(int u, int v)
{
    u = find_(u), v = find_(v);
    
    if (u == v) return;

    if (parent[u] > parent[v]) swap(u, v);

    parent[u] += parent[v];
    parent[v] = u;
}