#include <iostream>
#include <vector>

using namespace std;

struct island
{
    char type;
    int amount;
};

const int MAX = 123456 + 1;

int N;
vector< vector<int> > node(MAX);
island is[MAX];

long long dfs(int u, int p);
island make_island(char type, int amount);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    is[1] = make_island('S', 0);

    for (int v = 2; v <= N; v++)
    {
        char type; int amount, u;

        cin >> type >> amount >> u;

        is[v] = make_island(type, amount);

        node[u].push_back(v);
        node[v].push_back(u);
    }

    cout << dfs(1, -1) << "\n";

    return 0;
}

long long dfs(int u, int p)
{
    long long ret = is[u].type == 'S' ? is[u].amount : -is[u].amount;

    for (vector<int>::iterator i = node[u].begin(); i != node[u].end(); i++)
    {
        int v = (*i);

        if (v == p) continue;

        ret += dfs(v, u);
    }

    return max(ret, (long long) 0);
}

island make_island(char type, int amount)
{
    island i = { type, amount };
    return i;
}