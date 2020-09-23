#include <iostream>

using namespace std;

const int MAX = 101;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N, M, K;
bool board[MAX][MAX];
bool visited[MAX][MAX];

int find_trash(int x, int y);

int main(int argc, char const *argv[])
{
    cin >> N >> M >> K;

    while (K--)
    {
        int x, y; cin >> x >> y;
        board[x][y] = true;
    }

    int answer = 0;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (!visited[i][j] && board[i][j])
                answer = max(answer, find_trash(i, j));
    
    cout << answer << "\n";

    return 0;
}

int find_trash(int x, int y)
{
    visited[x][y] = true;

    int ret = 1;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 1 || nx > N || ny < 1 || ny > M)
            continue;
        
        if (visited[nx][ny] || !board[nx][ny])
            continue;
        
        ret += find_trash(nx, ny);
    }

    return ret;
}