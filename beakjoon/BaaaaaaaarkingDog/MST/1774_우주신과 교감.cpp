#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

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
    int u, v; double w;

    bool operator< (const edge &e) const
    {
        return w < e.w;
    }
};

const int MAX = 1e3;

int N, M;
edge e[MAX * MAX + 1];
pair<double, double> coordinate[MAX + 1];

double get_distance(pair<double, double> a, pair<double, double> b);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> coordinate[i].first >> coordinate[i].second;
    
    int idx = 0;

    for (int u = 1; u <= N; u++)
        for (int v = u + 1; v <= N; v++)
        {
            e[idx].u = u, e[idx].v = v;
            e[idx++].w = get_distance(coordinate[u], coordinate[v]);
        }

    sort(e, e + idx);
    union_find *g = new union_find(N);
    int cnt = 0; double sum_weight = 0;

    while (M--)
    {
        int u, v;
        cin >> u >> v;

        if (g->find(u) != g->find(v))
        {
            cnt += 1;
            g->merge(u, v);
        }
    }

    for (int i = 0; i < idx; i++)
    {
        if (cnt == N - 1)
            break;
        
        if (g->find(e[i].u) != g->find(e[i].v))
        {
            cnt += 1;
            g->merge(e[i].u, e[i].v);
            sum_weight += e[i].w;
        }
    }

    cout.precision(2);
    cout << fixed;
    cout << sum_weight << "\n";

    delete g;
    
    return 0;
}

double get_distance(pair<double, double> a, pair<double, double> b)
{
    return sqrt((b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second));
}
