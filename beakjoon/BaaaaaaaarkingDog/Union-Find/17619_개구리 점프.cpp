#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e5 + 1;

struct log
{
    int x1, x2, num;

    bool operator<(const log l)
    {
        return x1 < l.x1;
    }
};

int N, M;
int parent[MAX];
log logs[MAX];

int find_(int u);
void union_(int u, int v);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        int y;
        cin >> logs[i].x1 >> logs[i].x2 >> y;
        logs[i].num = i;
        parent[i] = i;
    }
    
    sort(&logs[1], &logs[1] + N);
   
    for (int v = 2; v <= N; v++)
    {
        int u = v - 1;

        if (logs[u].x2 >= logs[v].x1)
        {
            union_(logs[u].num, logs[v].num);
            logs[v].x2 = max(logs[u].x2, logs[v].x2);
        }
    }

    while (M--)
    {
        int u, v; cin >> u >> v;
        cout << (find_(u) == find_(v)) << "\n";
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

    parent[v] = u;
}
