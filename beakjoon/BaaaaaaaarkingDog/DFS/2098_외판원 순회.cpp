#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 16;
const int MAX_VALUE = 17000000;

int N;
int W[MAX][MAX];
int dp[(1 << MAX)][MAX];

int tsp(int visit, int now);

int main(int argc, char const *argv[])
{
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0 ; j < N; j++)
            cin >> W[i][j];

    int answer = tsp(0, 0);

    if (answer == MAX_VALUE)
        cout << -1 << "\n";
    else
        cout << answer << "\n";
    
    return 0;
}

int tsp(int visited, int current)
{
    visited |= ( 1 << current);

    if (visited == (1 << N) - 1)
    {
        if (W[current][0] > 0)
            return W[current][0];

        return MAX_VALUE;
    }

    int& ret = dp[visited][current];

    if (ret != 0)
        return ret;
    
    ret = MAX_VALUE;

    for (int i = 0; i < N; i++)
    {
        if (visited & (1 << i) || W[current][i] == 0)
            continue;

        ret = min(ret, tsp(visited, i) + W[current][i]);
    }

    return ret;
}
