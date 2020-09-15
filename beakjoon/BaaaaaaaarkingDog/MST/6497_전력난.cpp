#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 2e5 + 1;

class union_find
{
private:
    vector<int> parent;

public:
    union_find(int N)
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

struct edge
{
    int u, v, w;

    bool operator< (const edge &e) const
    {
        return w < e.w;
    }
};

int M, N;
edge e[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (true)
    {
        cin >> M >> N;

        if (M == 0 && N == 0)
            break;
        
        int sum_total = 0;

        for (int i = 0; i < N; i++)
        {
            cin >> e[i].u >> e[i].v >> e[i].w;
            sum_total += e[i].w;
        }
        
        sort(e, e + N);
        int cnt = 0, sum_weight = 0;
        union_find *g = new union_find(M);

        for (int i = 0; i < N; i++)
        {
            if (cnt == M - 1)
                break;

            if (g->find(e[i].u) != g->find(e[i].v))
            {
                cnt += 1;
                g->merge(e[i].u, e[i].v);
                sum_weight += e[i].w;
            }
        }

        cout << sum_total - sum_weight << "\n";

        delete g;
    }

    return 0;
}
