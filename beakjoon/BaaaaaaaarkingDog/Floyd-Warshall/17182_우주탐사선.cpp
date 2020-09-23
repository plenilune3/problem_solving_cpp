#include <iostream>

using namespace std;

const int MAX = 11;
const int MAX_VALUE = 10e8 + 1;

int N, K;
int T[MAX][MAX];
int dp[(1 << MAX)][MAX];

int tsp(int visited, int current);

int main(int argc, char const *argv[])
{
    cin >> N >> K;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> T[i][j];
    
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (T[i][j] > T[i][k] + T[k][j])
                    T[i][j] = T[i][k] + T[k][j];
    
    int answer = tsp(0, K);
    cout << answer << "\n";

    return 0;
}

int tsp(int visited, int current)
{
    visited |= (1 << current);

    if (visited == (1 << N) - 1)
        return 0;
   
    int &ret = dp[visited][current];

    if (ret != 0)
        return ret;
    
    ret = MAX_VALUE;
    
    for (int i = 0; i < N; i++)
    {
        if (visited & (1 << i) || current == i)
            continue;
        
        ret = min(ret, tsp(visited, i) + T[current][i]);
    }

    return ret;
}