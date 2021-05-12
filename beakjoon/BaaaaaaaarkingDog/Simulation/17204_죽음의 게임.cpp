#include <iostream>
#include <vector>

using namespace std;

const int MAX = 151;

int N, M, answer;
bool visited[MAX], possible;
vector< vector<int> > node(MAX);

void dfs(int d, int u);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int u = 0; u < N; u++)
    {
        int v; cin >> v;
        node[u].push_back(v);
    }

    dfs(0, 0);

    if (possible)
        cout << answer << "\n";
    else
        cout << -1 << "\n";

    return 0;
}

void dfs(int d, int u)
{
    visited[u] = true;

    if (u == M)
    {
        possible = true;
        answer = d;
    }

    for (vector<int>::iterator i = node[u].begin(); i != node[u].end(); i++)
    {
        int v = (*i);

        if (visited[v]) continue;

        dfs(d + 1, v);
    }
}