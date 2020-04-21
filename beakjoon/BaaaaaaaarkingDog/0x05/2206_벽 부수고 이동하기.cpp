#include <cstdio>
#include <queue>

using namespace std;

struct coordinate {
    int x;
    int y;
    int cnt;
    int depth;
};

const int MAX = 1000;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N, M;
int board[MAX][MAX] = { 0 };

int bfs( coordinate s )
{
    queue< coordinate > q;
    bool visited[MAX][MAX][2] = { false };
    visited[s.x][s.y][s.cnt] = true;
    q.push(s);

    while (!q.empty())
    {
        coordinate c = q.front();
        q.pop();

        if (c.x == N - 1 && c.y == M - 1)
            return c.depth;

        for (int i = 0; i < 4; i++)
        {
            int nx = c.x + dx[i];
            int ny = c.y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M )
                continue;
            
            if (board[nx][ny] == 1)
            {
                if (c.cnt == 0 && visited[nx][ny][0] == false)
                {
                    visited[nx][ny][0] = true;
                    coordinate nc = { nx, ny, 1, c.depth + 1};
                    q.push(nc);
                }
            }
            else
            {
                if (visited[nx][ny][c.cnt] == false)
                {
                    visited[nx][ny][c.cnt] = true;
                    coordinate nc = { nx, ny, c.cnt, c.depth + 1 };
                    q.push(nc);
                }
            }
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d\n", &N, &M);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%1d", &board[i][j]);
    
    coordinate s = {0, 0, 0, 1};
    int answer = bfs(s);

    printf("%d\n", answer);

    return 0;
}
