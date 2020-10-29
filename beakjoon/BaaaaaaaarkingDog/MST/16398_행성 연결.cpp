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

struct edge
{
    int u, v, w;

    bool operator< (const edge &e) const
    {
        return w < e.w;
    }
};

const int MAX = 1e3 + 1;

int N;
vector<edge> edges;

edge make_edge(int u, int v, int w);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int u = 1; u <= N; u++)
        for (int v = 1; v <= N; v++)
        {
            int w; cin >> w;
            edges.push_back(make_edge(u, v, w));
        }
    
    sort(edges.begin(), edges.end());

    int count_edge = 0;
    long long sum_weight = 0;
    union_find *g = new union_find();
    g->make_set(N);

    for (vector<edge>::iterator i = edges.begin(); i != edges.end(); i++)
    {
        if (count_edge == N - 1)
            break;
        
        if (g->find((*i).u) != g->find((*i).v))
        {
            count_edge += 1;
            g->merge((*i).u, (*i).v);
            sum_weight += (long long) (*i).w;
        }
    }

    delete g;

    cout << sum_weight << "\n";
    
    return 0;
}

edge make_edge(int u, int v, int w)
{
    edge e = { u, v, w };
    return e;
}
