#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 5e4 + 1;
const int MAX_M = 25e4 + 1;

int N, M;
int parent[MAX_N], in_degree[MAX_N];
vector< pair<int, int> > edge;
vector< vector<int> > node(MAX_N);

int find_(int u);
void union_(int u, int v);
bool is_consistent(vector< vector<int> > &node, int in_degree[MAX_N]);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int u = 0; u < N; u++)
        parent[u] = -1;

    while (M--)
    {
        int u, v; char ch;

        cin >> u >> ch >> v;

        if (ch == '=') union_(u, v);
        else if (ch == '>') edge.push_back(make_pair(u, v));
        else if (ch == '<') edge.push_back(make_pair(v, u));
    }

    for (vector< pair<int, int> >::iterator i = edge.begin(); i != edge.end(); i++)
    {
        int u = (*i).first, v = (*i).second;
        u = find_(u), v = find_(v);
        node[u].push_back(v);
        in_degree[v] += 1;
    }

    bool answer = is_consistent(node, in_degree);

    if (answer)
        cout << "consistent" << "\n";
    else
        cout << "inconsistent" << "\n";

    return 0;
}

bool is_consistent(vector< vector<int> > &node, int in_degree[MAX_N])
{
    queue<int> q;

    for (int i = 0; i < N; i++)
        if (in_degree[i] == 0)
            q.push(i);
    
    for (int i = 0; i < N; i++)
    {
        if (q.empty())
            return false;
        
        int u = q.front(); q.pop();

        for (vector<int>::iterator i = node[u].begin(); i != node[u].end(); i++)
            if (--in_degree[(*i)] == 0)
                q.push((*i));
    }

    return true;
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