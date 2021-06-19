#include <iostream>

using namespace std;

const int MAX = 101;

int N, M;
int parent[MAX];

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
        int x, y; cin >> x >> y;

        while (find_(x) != find_(y) && x < y)
        {
            int next = find_(x) + 1;
            union_(x, y);
            x = next;
        }
    }

    int answer = 0;

    for (int i = 1; i <= N; i++)
        if (find_(i) == i)
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
    u = find_(u), v = find_(v);

    if (u == v) return;

    if (u > v) swap(u, v);
    
    parent[u] += parent[v];
    parent[u] = v;
}