#include <iostream>
#include <stack>

using namespace std;

const int MAX = 3e5 + 1;

struct query
{
    int c, x;
};

int N, Q;
int parent[MAX], node[MAX];
bool disconnected[MAX];
query queries[MAX];

int find_(int u);
void union_(int u, int v);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> node[i];
        parent[i] = i;
    }
    
    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        cin >> queries[i].c >> queries[i].x;

        if (queries[i].c == 2)
            disconnected[queries[i].x] = true;
    }

    for (int i = 1; i <= N; i++)
        if (!disconnected[i] && node[i])
            union_(i, node[i]);
    
    stack<int> answer;

    for (int i = Q - 1; i >= 0; i--)
    {
        int c = queries[i].c, x = queries[i].x;

        if (c == 1)
            answer.push(find_(x));
        else if (c == 2)
            union_(x, node[x]);
    }

    while (!answer.empty())
    {
        if (answer.top() == 0)
            cout << "CIKLUS" << "\n";
        else
            cout << answer.top() << "\n";
        
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

    if (u == v)
    {
        parent[u] = parent[v] = 0;
        return;
    }

    parent[u] = v;
}
