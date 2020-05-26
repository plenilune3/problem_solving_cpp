#include <iostream>
#include <queue>

using namespace std;

const int MAX = 11;

struct marble
{
    int rx, ry, bx, by, depth;
    marble(int _rx, int _ry, int _bx, int _by, int _depth) : rx(_rx), ry(_ry), bx(_bx), by(_by), depth(_depth) {}
};

struct state
{
    int x, y, cnt;
    state(int _x, int _y, int _cnt) : x(_x), y(_y), cnt(_cnt) {}
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char board[MAX][MAX];
bool visited[MAX][MAX][MAX][MAX];
int N, M;

state move(int x, int y, int dx, int dy)
{
    int cnt = 0;

    while (board[x+dx][y+dy] != '#' && board[x][y] != 'O')
    {
        x = x + dx;
        y = y + dy;
        cnt++;
    }

    state m(x, y, cnt);

    return m;
}

int escape(int rx, int ry, int bx, int by, int tx, int ty)
{
    queue< marble > q;
    marble init(rx, ry, bx, by, 0);
    visited[rx][ry][bx][by] = true;
    q.push(init);

    while (!q.empty())
    {
        marble c = q.front();
        q.pop();

        if (c.depth > 10)
            break;

        if (board[c.rx][c.ry] == 'O')
            return c.depth;

        for (int i = 0; i < 4; i++)
        {
            state red = move(c.rx, c.ry, dx[i], dy[i]);
            state blue = move(c.bx, c.by, dx[i], dy[i]);

            if (board[blue.x][blue.y] == 'O')
                continue;

            if (red.x == blue.x && red.y == blue.y)
            {
                if (red.cnt > blue.cnt)
                {
                    red.x -= dx[i];
                    red.y -= dy[i];
                }
                else
                {
                    blue.x -= dx[i];
                    blue.y -= dy[i];
                }
            }

            if (visited[red.x][red.y][blue.x][blue.y] == false)
            {
                visited[red.x][red.y][blue.x][blue.y] = true;
                marble nm(red.x, red.y, blue.x, blue.y, c.depth + 1);
                q.push(nm);
            }
            
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    cin >> N >> M;

    int rx, ry, bx, by, tx, ty;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 'R')
                rx = i, ry = j;
            else if (board[i][j] == 'B')
                bx = i, by = j;
            else if (board[i][j] == 'O')
                tx = i, ty = j;
        }
    
    int answer = escape(rx, ry, bx, by, tx, ty);

    cout << answer << "\n";

    return 0;
}
