#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MAX = 2e5 + 1;

class union_find
{
private:
    vector<int> parent;
public:
    union_find ()
    {
        parent = vector<int> (MAX, -1);
    }

    int size(int u)
    {
        if (parent[u] < 0) return -parent[u];
        else return -parent[find(u)];
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

int T, F;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;

    while (T--)
    {
        cin >> F;

        int idx = 1;
        map<string, int> name;

        union_find *g = new union_find();

        while (F--)
        {
            string a, b; cin >> a >> b;

            if (name[a] == 0) name[a] = idx++;
            if (name[b] == 0) name[b] = idx++;

            int u = g->find(name[a]), v = g->find(name[b]);
            g->merge(u, v);

            cout << g->size(u) << "\n";
        }

        delete g;
    }

    return 0;
}
