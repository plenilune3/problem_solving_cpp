#include <iostream>

using namespace std;

const int MAX = 51;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N, M;
bool visited[MAX][MAX], is_cycled;
int dp[MAX][MAX];
int board[MAX][MAX];

int play(int depth, int x, int y);

int main(int argc, char const *argv[])
{
    fill_n(&dp[0][0], MAX * MAX, -1);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string row; cin >> row;

        for (int j = 0; j < M; j++)
            if (row[j] == 'H') board[i][j] = 0;
            else board[i][j] = row[j] - '0';
    }

    int answer = play(0, 0, 0);

    if (!is_cycled)
        cout << answer << "\n";
    else
        cout << -1 << "\n";

    return 0;
}

int play(int depth, int x, int y)
{
    int &ret = dp[x][y];

    if (ret != -1) return ret;

    ret = 1;

    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int k = board[x][y];
        int nx = x + (dx[i] * k), ny = y + (dy[i] * k);

        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;
        
        if (board[nx][ny] == 0)
            continue;
        
        if (visited[nx][ny])
            is_cycled = true;
        
        ret = max(ret, play(depth + 1, nx, ny) + 1);
    }

    visited[x][y] = false;

    return ret;
}

