#include <iostream>
#include <queue>

using namespace std;

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

struct state
{
    int x, y, cnt, depth;
};

int N, M, K;
char board[1000][1000];
bool visited[1000][1000][11];

int bfs()
{
    state init = { 0, 0, 0, 0 };
    queue<state> q;
    visited[0][0][0] = true;
    q.push(init);

    while(!q.empty())
    {
        state c = q.front();
        q.pop();

        if (c.x == N - 1 && c.y == M - 1)
            return c.depth + 1;
        
        for (int i = 0; i < 4; i++)
        {
            int nx = c.x + dx[i], ny = c.y + dy[i], k = c.cnt;

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            
            if (board[nx][ny] == '0' && visited[nx][ny][k] == false)
            {
                state n = { nx, ny, k, c.depth + 1 };
                visited[nx][ny][k] = true;
                q.push(n);
            } 
            else if (k < K && visited[nx][ny][k + 1] == false)
            {
                state n = { nx, ny, k + 1, c.depth + 1 };
                visited[nx][ny][k + 1] = true;
                q.push(n);
            }
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    
    int answer = bfs();
    cout << answer << "\n";

    return 0;
}
