#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int MAX = 2e5 + 1;

int N, M, barn[MAX];
bool visited[MAX];
vector< vector<int> > graph(MAX);
vector<int> parent(MAX, -1);

int find_(int u);
void union_(int u, int v);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    while (M--)
    {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < N; i++)
        cin >> barn[i];
    
    int cnt = 0;
    stack<bool> answer;

    for (int i = N - 1; i >= 0; i--)
    {
        int u = barn[i];
        visited[u] = true;

        if (i == N - 1)
        {
            answer.push(true);
            cnt += 1;
            continue;
        }

        for (vector<int>::iterator i = graph[u].begin(); i != graph[u].end(); i++)
        {
            int v = (*i);

            if (visited[v])
                union_(u, v);
        }

        answer.push(-parent[find_(u)] == ++cnt);
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
