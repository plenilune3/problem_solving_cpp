#include <iostream>
#include <vector>

using namespace std;

const int MAX = 27;

int N, M, K;
vector< vector<int> > node(MAX);
int in_degree[MAX];
bool visited[MAX];

int dfs(int x);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    while (M--)
    {
        char a, b; cin >> a >> b;
        int u = a - 'A', v = b - 'A';

        in_degree[v] =+ 1;
        node[u].push_back(v);
        node[v].push_back(u);
    }

    cin >> K;

    while (K--)
    {
        char c; cin >> c;
        int u = c - 'A';

        visited[u] = true;
    }

    int answer = 0;

    for (int i = 0; i < N; i++)
        if (in_degree[i] == 0 && visited[i] == false)
            answer += dfs(i) - 1;

    cout << answer << "\n";

    return 0;
}

int dfs(int x)
{
    visited[x] = true;

    int ret = 1;

    for (vector<int>::iterator i = node[x].begin(); i != node[x].end(); i++)
    {
        int nx = (*i);

        if (visited[nx]) continue;

        ret += dfs(nx);
    }

    return ret;
}
