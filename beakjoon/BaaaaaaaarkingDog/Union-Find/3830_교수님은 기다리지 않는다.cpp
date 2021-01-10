#include <iostream>

using namespace std;

const int MAX = 1e5 + 1;

int N, M;
int parent[MAX];
long long diff[MAX];

int find_(int u);
void union_(int u, int v, int w);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (true)
    {
        cin >> N >> M;

        if (N == 0 && M == 0)
            break;
        
        for (int i = 0; i <= N; i++)
            parent[i] = i, diff[i] = 0;
        
        for (int i = 0; i < M; i++)
        {
            char ch; cin >> ch;

            if (ch == '!')
            {
                int u, v, w; cin >> u >> v >> w;
                union_(u, v, w);
            }
            else
            {
                int u, v; cin >> u >> v;

                if (find_(u) != find_(v))
                    cout << "UNKNOWN" << "\n";
                else
                    cout << diff[v] - diff[u] << "\n";
            }
        }
    }

    return 0;
}

int find_(int u)
{
    if (parent[u] == u)
        return u;
    else
    {
        int v = find_(parent[u]);
        diff[u] += diff[parent[u]];
        return parent[u] = v;
    }
}

void union_(int u, int v, int w)
{
    int pu = find_(u), pv = find_(v);

    if (pu == pv) return;

    diff[pv] = diff[u] + w - diff[v];
    parent[pv] = parent[pu];
}