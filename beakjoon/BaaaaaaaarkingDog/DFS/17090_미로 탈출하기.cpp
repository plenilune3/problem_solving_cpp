#include <iostream>

using namespace std;

const int MAX = 501;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N, M, answer;
int board[MAX][MAX];
int dp[MAX][MAX];

int find_exit(int x, int y);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string row; cin >> row;

        for (int j = 0; j < M; j++)
            if (row[j] == 'U') board[i][j] = 0;
            else if (row[j] == 'D') board[i][j] = 1;
            else if (row[j] == 'L') board[i][j] = 2;
            else board[i][j] = 3;
    }

    for (int x = 0; x < N; x++)
        for (int y = 0; y < M; y++)
            find_exit(x, y) == 2 ? answer += 1 : answer;
    
    cout << answer << "\n";

    return 0;
}

int find_exit(int x, int y)
{
    if (dp[x][y])
        return dp[x][y];
    
    dp[x][y] = 1;

    int dir = board[x][y];
    int nx = x + dx[dir], ny = y + dy[dir];

    if (nx < 0 || nx >= N || ny < 0 || ny >= M)
        return dp[x][y] = 2;
    
    return dp[x][y] = find_exit(nx, ny);
}
