#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1e3 + 1;
const int MAX_M = 1e5 + 1;

class union_find
{
private:
    vector<int> parent;
    vector<bool> is_generator;
public:
    void make_set(int N)
    {
        parent = vector<int> (N + 1, -1);
        is_generator = vector<bool> (N + 1, false);
    }

    void set_generator(int u)
    {
        is_generator[u] = true;
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

        if (is_generator[v]) swap(u, v);
        
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

int N, M, K;
bool is_generator[MAX_N];
edge edges[MAX_M];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> K;

    union_find *g = new union_find();
    g->make_set(N);
    
    for (int i = 0; i < K; i++)
    {
        int num; cin >> num;
        is_generator[num] = true;
        g->set_generator(num);
    }

    for (int i = 0; i < M; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    
    sort(edges, edges + M);

    int count_edge = 0; long long sum_weight = 0;

    for (int i = 0; i < M; i++)
    {
        if (count_edge == (N - 1) - (K - 1))
            break;
        
        bool is_disjoint = g->find(edges[i].u) != g->find(edges[i].v);
        bool is_possible = !(is_generator[g->find(edges[i].u)] && is_generator[g->find(edges[i].v)]);

        if (is_disjoint && is_possible)
        {
            g->merge(edges[i].u, edges[i].v);
            count_edge += 1;
            sum_weight += (long long) edges[i].w;
        }
    }

    delete g;

    cout << sum_weight << "\n";
    
    return 0;
}
