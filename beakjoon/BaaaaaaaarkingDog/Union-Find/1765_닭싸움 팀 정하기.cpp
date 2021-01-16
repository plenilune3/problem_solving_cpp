#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e3 + 1;

int N, M;
int parent[MAX];
vector<int> enemey[MAX];

int find_(int u);
void union_(int u, int v);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        parent[i] = -1;

    while (M--)
    {
        char ch; int p, q;
        cin >> ch >> p >> q;

        if (ch == 'F') union_(p, q);
        else if (ch == 'E')
        {
            enemey[p].push_back(q);
            enemey[q].push_back(p);
        }
    }

    for (int p = 1; p <= N; p++)
        for (vector<int>::iterator i = enemey[p].begin(); i != enemey[p].end(); i++)
            union_(*enemey[p].begin(), *i);
    
    int answer = 0;
    
    for (int p = 1; p <= N; p++)
        if (find_(p) == p)
            answer += 1;
    
    cout << answer << "\n";

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
    u = find_(u) , v = find_(v);

    if (u == v) return;

    if (parent[u] > parent[v]) swap(u, v);

    parent[u] += parent[v];
    parent[v] = u;
}
