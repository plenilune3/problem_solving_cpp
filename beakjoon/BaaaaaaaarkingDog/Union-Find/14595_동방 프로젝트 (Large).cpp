#include <iostream>

using namespace std;

const int MAX = 1e6 + 1;

int N, M;
int parent[MAX];

int find_(int u);
void union_(int u, int v);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        parent[i] = i;
    
    while (M--)
    {
        int u, v; cin >> u >> v;

        while (find_(u) != find_(v))
        {
            u = find_(u), v = find_(v);
            union_(u++, v);
        }
    }

    int answer = 0;

    for (int u = 1; u <= N; u++)
        if (parent[find_(u)] == u)
            answer += 1;
    
    cout << answer << "\n";

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

    parent[u] = v;
}