#include <iostream>

using namespace std;

const int MAX = 1e3 + 1;

int N, M;
int parent[MAX];

int find_(int u);
void union_(int u, int v);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T; cin >> T;

    while (T--)
    {
        bool answer = true;

        cin >> N >> M;

        for (int i = 0; i <= N; i++)
            parent[i] = -1;
        
        while (M--)
        {
            int u, v; cin >> u >> v;

            if (find_(u) == find_(v))
                answer = false;

            union_(u, v);
        }

        if (-parent[find_(1)] != N)
            answer = false;

        if (answer)
            cout << "tree" << "\n";
        else
            cout << "graph" << "\n";
    }

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
