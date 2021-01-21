#include <iostream>

using namespace std;

const int MAX = 501;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N;
int board[MAX][MAX], dp[MAX][MAX];

int dfs(int x, int y);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    fill_n(&dp[0][0], MAX * MAX, -1);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    
    int answer = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            answer = max(answer, dfs(i, j));
    
    cout << answer << "\n";
    
    return 0;
}

int dfs(int x, int y)
{
    int &ret = dp[x][y];

    if (ret != -1) return ret;

    ret = 1;

    for (int d = 0; d < 4; d++)
    {
        int nx = x + dx[d], ny = y + dy[d];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue;
        
        if (board[x][y] >= board[nx][ny])
            continue;
        
        ret = max(ret, 1 + dfs(nx, ny));
    }

    return ret;
}
