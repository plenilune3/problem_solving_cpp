#include <iostream>
#include <queue>

using namespace std;

const int MAX = 200;
const int dx[] = { -2, -2, 0, 0, 2, 2};
const int dy[] = { -1, 1, -2, 2, -1, 1};

int N;

int bfs(int sx, int sy, int tx, int ty)
{
    int dist[MAX][MAX];
    fill_n(&dist[0][0], MAX * MAX, -1);
    queue< pair<int, int> > q;
    dist[sx][sy] = 0;
    q.push(make_pair(sx, sy));

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();

        if (x == tx && y == ty)
            return dist[x][y];
        
        for (int i = 0; i < 6; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N || dist[nx][ny] != -1)
                continue;
            
            dist[nx][ny] = dist[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    int sx, sy, tx, ty;

    cin >> N;
    cin >> sx >> sy >> tx >> ty;

    cout << bfs(sx, sy, tx, ty) << "\n";

    return 0;
}
