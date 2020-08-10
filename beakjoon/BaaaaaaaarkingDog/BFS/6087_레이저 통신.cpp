#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 102;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int W, H;
char board[MAX][MAX];
int dist[MAX][MAX];

void forwardLight(int x, int y, int mirrorCount, queue< pair<int, int> > &q)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 0 || nx >= H + 2 || ny < 0 || ny > W + 2)
            continue;

        while (board[nx][ny] != '*')
        {
            if (dist[nx][ny] == -1)
            {
                q.push(make_pair(nx, ny));
                dist[nx][ny] = mirrorCount;
            }

            nx += dx[i], ny += dy[i];
        }
    }
}

int bfs(vector< pair<int, int> > &v)
{
    queue< pair<int, int> > q;
    fill_n(&dist[0][0], MAX * MAX, -1);

    int sx = v.back().first, sy = v.back().second;
    v.pop_back();
    int tx = v.back().first, ty = v.back().second; 
    v.pop_back();

    dist[sx][sy] = 0;
    q.push(make_pair(sx, sy));

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();

        if (x == tx && y == ty)
            return dist[x][y];
        
        forwardLight(x, y, dist[x][y] + 1, q);
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    vector< pair<int, int> > v;
    cin >> W >> H;

    for (int i = 0; i <= H + 1; i++)
        for (int j = 0; j <= W + 1; j++)
        {
            if (i == 0 || j == 0 || i == H + 1 || j == W + 1)
            {
                board[i][j] = '*';
                continue;
            }

            cin >> board[i][j];

            if (board[i][j] == 'C')
            {
                v.push_back(make_pair(i, j));
                board[i][j] = '.';
            }
        }

    cout << bfs(v) - 1 << "\n";

    return 0;
}
