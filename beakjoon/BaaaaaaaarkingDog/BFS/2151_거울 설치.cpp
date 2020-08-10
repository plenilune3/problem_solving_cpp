#include <iostream>
#include <queue>

using namespace std;

const int MAX = 52;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

struct state
{
    int x, y, d;
};

int N;
char board[MAX][MAX];
int dist[MAX][MAX][4];

bool is_possible(int x, int y, int d)
{
    if (x < 0 || x >= N || y < 0 || y >= N)
        return false;
    if (dist[x][y][d] == '*')
        return false;
    
    return true;
}

void move(int &nx, int &ny, int d)
{
    while (is_possible(nx, ny, d) && board[nx][ny] == '.')
    {
        nx += dx[d];
        ny += dy[d];
    }
}

int bfs(int sx, int sy, int tx, int ty)
{
    fill_n(&dist[0][0][0], MAX * MAX * 4, -1);
    queue<state> q;

    for (int i = 0; i < 4; i++)
    {
        state init = { sx, sy, i };
        dist[sx][sy][i] = 0;
        q.push(init);
    }

    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y, d = q.front().d;
        q.pop();

        if (x == tx && y == ty)
            return dist[x][y][d];

        int nx = x + dx[d], ny = y + dy[d];
        move(nx, ny, d);

        if (board[nx][ny] == '!' || board[nx][ny] == '#')
        {
            state n = { nx, ny, d };
            dist[nx][ny][d] = dist[x][y][d];
            q.push(n);

            int k = d < 2 ? 2 : 0;
            for (int i = k; i < k + 2; i++)
                if (dist[nx][ny][i] == -1)
                {
                    state c = { nx, ny, i };
                    dist[nx][ny][i] = dist[x][y][d] + 1;
                    q.push(c);
                }
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int sx = - 1, sy = -1, tx = -1, ty = -1;
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == '#')
            {
                if (sx == -1)
                    sx = i, sy = j;
                else
                    tx = i, ty = j;
            }
        }
    
    int answer = bfs(sx, sy, tx, ty);
    cout << answer << "\n";

    return 0;
}
