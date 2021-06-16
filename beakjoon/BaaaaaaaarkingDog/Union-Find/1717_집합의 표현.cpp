#include <iostream>

using namespace std;

const int MAX = 1e6 + 1;

int N, M, parent[MAX];

int find_(int u);
void union_(int u, int v);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    fill_n(&parent[0], MAX, -1);

    cin >> N >> M;

    while (M--)
    {
        int a, b, c; cin >> a >> b >> c;

        if (a == 1)
        {
            if (find_(b) == find_(c))
                cout << "YES" << "\n";
            else
                cout << "NO" << "\n";
        }
        else
            union_(b, c);
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

    if (u > v) swap(u, v);
    parent[u] += parent[v];
    parent[v] = u;
}
