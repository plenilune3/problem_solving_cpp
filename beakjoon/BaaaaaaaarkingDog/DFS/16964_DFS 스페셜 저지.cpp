#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int MAX = 1e5 + 1;

int N, idx;
bool visited[MAX], possible = true;
vector< vector<int> > node(MAX, vector<int> ());
vector<int> order;

void dfs(int u);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> N;

    for (int i = 1; i <= N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
    {
        int x; cin >> x;
        order.push_back(x);
    }

    if (order[0] != 1)
    {
        cout << 0 << "\n";
        return 0;
    }

    dfs(1);

    if (possible)
        cout << 1 << "\n";
    else
        cout << 0 << "\n";

	return 0;
}

void dfs(int u)
{
    set<int> s;
    visited[u] = true;

    for (vector<int>::iterator i = node[u].begin(); i != node[u].end(); i++)
    {
        int nv = (*i);
        if (visited[nv]) continue;
        s.insert(nv);
    }

    if (s.empty())
        return;

    if (s.find(order[idx + 1]) != s.end())
        dfs(order[++idx]);
    else
        possible = false;
}
