#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e4 + 1;

int N;
int villager[MAX], dp[MAX][2];
bool visited[MAX];
vector< vector<int> > node(MAX);
vector< vector<int> > tree(MAX);

void create_tree(int x);
int get_excellent(int x, bool is_excellent);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    fill_n(&dp[0][0], MAX * 2, -1);

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> villager[i];
    
    for (int i = 0; i < N - 1; i++)
    {
        int u, v; cin >> u >> v;

        node[u].push_back(v);
        node[v].push_back(u);
    }

    create_tree(1);

    int answer = max(get_excellent(1, 0), get_excellent(1, 1));

    cout << answer << "\n";

    return 0;
}

void create_tree(int x)
{
    visited[x] = true;

    for (vector<int>::iterator iter = node[x].begin(); iter != node[x].end(); iter++)
    {
        int nx = (*iter);

        if (visited[nx]) continue;

        tree[x].push_back(nx);
        create_tree(nx);
    }
}

int get_excellent(int x, bool is_excellent)
{
    if (dp[x][is_excellent] != -1)
        return dp[x][is_excellent];
    
    dp[x][is_excellent] = is_excellent ? villager[x] : 0;

    for (vector<int>::iterator iter = tree[x].begin(); iter != tree[x].end(); iter++)
    {
        int nx = (*iter);

        if (is_excellent)
            dp[x][is_excellent] += get_excellent(nx, 0);
        else
            dp[x][is_excellent] += max(get_excellent(nx, 1), get_excellent(nx, 0));
    }

    return dp[x][is_excellent];
}
