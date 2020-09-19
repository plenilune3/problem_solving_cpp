#include <iostream>
#include <vector>
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
    int u, v, w;
};

bool desc(edge &a, edge &b)
{
    return a.w > b.w;
}

bool asc(edge &a, edge &b)
{
    return a.w < b.w;
}

const int MAX_N = 1e3 + 1;
const int MAX_M = MAX_N * (MAX_N - 1) / 2;

int N, M;
edge e[MAX_M];

int get_fatigue(edge e[MAX_M]);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    cin >> e[0].u >> e[0].v >> e[0].w;

    for (int i = 1; i <= M; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;
    
    sort(&e[1], &e[1] + M, desc);
    int min_fatigue = get_fatigue(e);

    sort(&e[1], &e[1] + M, asc);
    int max_fatigue = get_fatigue(e);

    int answer = (max_fatigue) * (max_fatigue) - (min_fatigue) * (min_fatigue);
    cout << answer << "\n";

    return 0;
}

int get_fatigue(edge e[MAX_M])
{
    union_find *g = new union_find(N + 1);
    int cnt = 0, sum_weight = 0;

    g->merge(e[0].u, e[0].v);
    cnt += 1, sum_weight += (e[0].w == 0);

    for (int i = 1; i <= M; i++)
    {
        if (cnt == N)
            break;
        
        if (g->find(e[i].u) != g->find(e[i].v))
        {
            g->merge(e[i].u, e[i].v);
            cnt += 1, sum_weight += (e[i].w == 0);
        }
    }

    delete g;
    return sum_weight;
}
