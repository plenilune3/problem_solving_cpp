#include <iostream>

using namespace std;

const int MAX = 1e6 + 1;

int N, M, Q;
long long answer;
int parent[MAX], disconnect[MAX];
bool connection[MAX];
pair<int, int> connections[MAX];

int find_(int u);
void union_(int u, int v);
int count_(int u);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> Q;

    fill_n(&parent[0], MAX, -1);

    for (int i = 1; i <= M; i++)
    {
        cin >> connections[i].first >> connections[i].second;
        connection[i] = true;
    }
    
    for (int i = 1; i <= Q; i++)
    {
        cin >> disconnect[i];
        connection[disconnect[i]] = false;
    }

    for (int i = 1; i <= M; i++)
        if (connection[i])
            union_(connections[i].first, connections[i].second);

    for (int i = Q; i >= 1; i--)
    {
        int u = connections[disconnect[i]].first, v = connections[disconnect[i]].second;

        if (find_(u) != find_(v))
            answer += (long long) count_(u) * (long long) count_(v);
        
        union_(u, v);
    }

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
    u = find_(u), v = find_(v);

    if (u == v) return;

    if (parent[u] > parent[v]) swap(u, v);

    parent[u] += parent[v];
    parent[v] = u;
}

int count_(int u)
{
    return parent[find_(u)];
}
