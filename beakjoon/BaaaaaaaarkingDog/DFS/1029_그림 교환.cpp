#include <iostream>

using namespace std;

const int MAX = 16;

int N;
int adj[MAX][MAX];
int dp[(1 << MAX)][MAX][10];

int tsp(int visited, int x, int value);

int main(int argc, char const *argv[])
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string row; cin >> row;

        for (int j = 0; j < N; j++)
            adj[i][j] = row[j] - '0';
    }

    cout << tsp(0, 0, 0) << "\n";

    return 0;
}

int tsp(int visited, int x, int value)
{
    visited |= (1 << x);

    if (visited == (1 << N) - 1)
        return 1;

    int &ret = dp[visited][x][value];

    if (ret != 0) return ret;

    ret = 1;

    for (int i = 0; i < N; i++)
    {
        if (visited & (1 << i) || x == i)
            continue;
        
        if (value > adj[x][i])
            continue;
        
        ret = max(ret, tsp(visited, i, adj[x][i]) + 1);
    }

    return ret;
}
