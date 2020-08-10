#include <iostream>
#include <queue>

using namespace std;

const int MAX = 10;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

struct state
{
    int rx, ry, bx, by, depth;
};

struct marble
{
    int x, y, cnt;
};

int N, M;
char board[MAX][MAX];
bool visited[MAX][MAX][MAX][MAX];

marble move(int x, int y, int dx, int dy)
{
    int cnt = 0;

    while(board[x + dx][y + dy] != '#' && board[x][y] != 'O')
    {
        x += dx;
        y += dy;
        cnt += 1;
    }

    marble m = { x, y, cnt };

    return m;
}

int bfs(state init)
{
    queue<state> q;
    visited[init.rx][init.ry][init.bx][init.by] = true;
    q.push(init);

    while(!q.empty())
    {
        state c = q.front();
        q.pop();

        if (board[c.rx][c.ry] == 'O')
            return c.depth;

        for (int i = 0; i < 4; i++)
        {
            marble red = move(c.rx, c.ry, dx[i], dy[i]);
            marble blue = move(c.bx, c.by, dx[i], dy[i]);

            if (board[blue.x][blue.y] == 'O')
                continue;
            
            if (red.x == blue.x && red.y == blue.y)
            {
                if (blue.cnt > red.cnt)
                    blue.x -= dx[i], blue.y -= dy[i];
                else
                    red.x -= dx[i], red.y -= dy[i];
            }

            if (visited[red.x][red.y][blue.x][blue.y] == false)
            {
                state nc = { red.x, red.y, blue.x, blue.y, c.depth + 1 };
                visited[red.x][red.y][blue.x][blue.y] = true;
                q.push(nc);
            }
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    state init;
    init.depth = 0;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 'R')
                init.rx = i, init.ry = j;
            else if (board[i][j] == 'B')
                init.bx = i, init.by = j;
        }
    
    int answer = bfs(init);
    cout << answer << "\n";
    
    return 0;
}
