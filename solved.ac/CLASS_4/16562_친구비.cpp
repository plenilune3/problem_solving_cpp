#include <iostream>
#include <vector>

using namespace std;

class union_find
{
private:
    vector<int> parent;
    vector<int> weight;
public:
    union_find(int N, vector<int> w)
    {
        parent = vector<int> (N + 1, -1);
        weight = w;
    }

    int find(int u)
    {
        if (parent[u] < 0) return u;

        int v = find(parent[u]);
        parent[u] = v;

        return v;
    }

    int merge(int u, int v)
    {
        u = find(u), v = find(v);

        if (u == v) return 0;

        if (weight[u] > weight[v]) swap(u, v);

        parent[u] += parent[v];
        parent[v] = u;

        return weight[v];
    }
};

int N, M, K, answer;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> K;

    vector<int> w(N + 1, 0);

    for (int i = 1; i <= N; i++)
        cin >> w[i];
    
    union_find *g = new union_find(N, w);

    while (M--)
    {
        int u, v; cin >> u >> v;
        g->merge(u, v);
    }

    for (int u = 1; u <= N; u++)
        if (g->find(u) != 0)
            answer += g->merge(0, u);
    
    if (answer <= K)
        cout << answer << "\n";
    else
        cout << "Oh no" << "\n";
    
    delete g;

    return 0;
}
