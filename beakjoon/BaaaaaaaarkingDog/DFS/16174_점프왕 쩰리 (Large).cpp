#include <iostream>

using namespace std;

const int MAX = 64 + 1;
const int dx[] = { 1, 0 };
const int dy[] = { 0, 1 };

int N;
int board[MAX][MAX];
int dp[MAX][MAX];

bool dfs(int x, int y);

int main(int argc, char const *argv[])
{
    fill_n(&dp[0][0], MAX * MAX, -1);
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    
    bool is_possible = dfs(0, 0);

    if (is_possible)
        cout << "HaruHaru" << "\n";
    else
        cout << "Hing" << "\n";

    return 0;
}

bool dfs(int x, int y)
{
    if (dp[x][y] != -1) return dp[x][y];

    if (board[x][y] == -1)
        return true;
    
    dp[x][y] = 0;
    int k = board[x][y];

    for (int i = 0; i < 2; i++)
    {
        int nx = x + dx[i] * k, ny = y + dy[i] * k;

        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue;
        
        dp[x][y] |= dfs(nx, ny);
    }

    return dp[x][y];
}

