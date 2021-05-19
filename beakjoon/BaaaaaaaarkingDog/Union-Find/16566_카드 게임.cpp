#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 4e6 + 1;

int N, M, K;
int parent[MAX], blue[MAX];

int find_(int u);
void union_(int u, int v);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 0; i < M; i++)
    {
        cin >> blue[i];
        parent[blue[i]] = blue[i];
    }
    
    sort(&blue[0], &blue[0] + M);

    while (K--)
    {
        int x; cin >> x;
        int p = upper_bound(&blue[0], &blue[0] + M, x) - &blue[0];

        cout << find_(blue[p]) << "\n";

        p = upper_bound(&blue[0], &blue[0] + M, find_(blue[p])) - &blue[0];

        union_(blue[p - 1], blue[p]);
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
        return parent[u] = v;
    }
}

void union_(int u, int v)
{
    u = find_(u), v = find_(v);

    if (u == v) return;

    if (u > v) swap(u, v);

    parent[u] = v;
}

