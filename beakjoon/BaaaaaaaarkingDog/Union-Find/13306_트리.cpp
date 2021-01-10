#include <iostream>
#include <stack>

using namespace std;

const int MAX = 2e5 + 1;

struct query
{
    int x, u, v;
};

int N, Q; 
int parent[MAX];
int parent_num[MAX];
query queries[MAX * 2];

int find_(int u);
void union_(int u, int v);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> Q;

    for (int i = 0; i < MAX; i++)
        parent[i] = i;
    
    parent_num[1] = 1;

    for (int i = 2; i <= N; i++)
    {
        int u; cin >> u;
        parent_num[i] = u;
    }

    Q += N - 1;

    for (int i = 0; i < Q; i++)
    {
        cin >> queries[i].x >> queries[i].u;

        if (queries[i].x == 1)
            cin >> queries[i].v;
    }

    stack<bool> answer;

    for (int i = Q - 1; i >= 0; i--)
    {
        if (queries[i].x == 0)
            union_(queries[i].u, parent_num[queries[i].u]);
        else
            answer.push(find_(queries[i].u) == find_(queries[i].v));
    }

    while (!answer.empty())
    {
        if (answer.top())
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
        
        answer.pop();
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

    parent[u] = v;
}
