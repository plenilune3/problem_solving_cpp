#include <iostream>
#include <queue>

using namespace std;

const int MAX = 11;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

struct ball 
{
    int rx, ry, bx, by;
};

int N, M;
char board[MAX][MAX];
int dist[MAX][MAX][MAX][MAX];

int bfs(ball init);
int move(int &x, int &y, int d);
ball make_ball(int rx, int ry, int bx, int by);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    ball init;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string row; cin >> row;

        for (int j = 0; j < M; j++)
        {
            board[i][j] = row[j];

            if (board[i][j] == 'R')
                init.rx = i, init.ry = j;
            else if (board[i][j] == 'B')
                init.bx = i, init.by = j;
        }
    }

    int answer = bfs(init);

    cout << answer << "\n";
    
    return 0;
}

int bfs(ball init)
{
    int dist[MAX][MAX][MAX][MAX];
    fill_n(&dist[0][0][0][0], MAX * MAX * MAX * MAX, -1);

    queue<ball> q;
    dist[init.rx][init.ry][init.bx][init.by] = 0;
    q.push(init);

    while (!q.empty())
    {
        int rx = q.front().rx, ry = q.front().ry, bx = q.front().bx, by = q.front().by;
        q.pop();

        if (dist[rx][ry][bx][by] > 10)
            break;
        
        if (board[rx][ry] == 'O')
            return dist[rx][ry][bx][by];

        for (int i = 0; i < 4; i++)
        {
            int nrx = rx, nry = ry, nbx = bx, nby = by;
            int red_ball = move(nrx, nry, i);
            int blue_ball = move(nbx, nby, i);

            if (board[nbx][nby] == 'O')
                continue;
            
            if (nrx == nbx && nry == nby)
            {
                if (red_ball > blue_ball) nrx -= dx[i], nry -= dy[i];
                else if (blue_ball > red_ball) nbx -= dx[i], nby -= dy[i];
            }

            if (dist[nrx][nry][nbx][nby] != -1)
                continue;

            dist[nrx][nry][nbx][nby] = dist[rx][ry][bx][by] + 1;
            q.push(make_ball(nrx, nry, nbx, nby));
        }
    }

    return -1;
}

int move(int &x, int &y, int d)
{
    int counter = 0;

    while (board[x + dx[d]][y + dy[d]] != '#' && board[x][y] != 'O')
    {
        counter += 1;
        x += dx[d], y += dy[d];
    }

    return counter;
}

ball make_ball(int rx, int ry, int bx, int by)
{
    ball b = { rx, ry, bx, by };
    return b;
}
