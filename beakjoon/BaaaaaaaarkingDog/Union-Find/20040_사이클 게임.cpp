#include <iostream>

using namespace std;

const int MAX = 5e5 + 1;

int N, M, answer;
int parent[MAX];

int find_(int u);
void union_(int u, int v);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;
    fill_n(&parent[0], MAX, -1);

    for (answer = 1; answer <= M; answer++)
    {
        int u, v; cin >> u >> v;

        if (find_(u) == find_(v))
            break;
        
        union_(u, v);
    }

    if (answer != M + 1)
        cout << answer << "\n";
    else
        cout << 0 << "\n";

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

    if (u > v) swap(u, v);

    parent[u] += parent[v];
    parent[v] = u;
}
