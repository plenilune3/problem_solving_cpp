#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e5 + 1;

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

        return parent[u] = find(parent[u]);
    }

    void merge(int u, int v)
    {
        u = find(u), v = find(v);
        
        if (u == v) return;

        if (u > v) swap(u, v);

        parent[u] += parent[v];
        parent[v] = u;
    }
};

int G, P, answer;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> G >> P;

    union_find *g = new union_find(G);

    while (P--)
    {
        int u; cin >> u;
        int parent = g->find(u);

        if (parent == 0)
            break;
        
        g->merge(parent - 1, parent);

        answer += 1;
    }

    cout << answer << "\n";

    delete g;

    return 0;
}
