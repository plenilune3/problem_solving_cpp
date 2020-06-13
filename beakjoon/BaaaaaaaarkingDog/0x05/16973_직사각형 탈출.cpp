#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1000;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N, M, H, W;
int sx, sy, tx, ty;
int board[MAX][MAX];
int dist[MAX][MAX];

bool is_possible(int x, int y)
{
    if (x + H >= N || y + W >= M)
        return false;
    
    for (int i = x; i <= x + H; i++)
        for (int j = y; j <= y + W; j++)
            if (board[i][j])
                return false;
    
    return true;
}

int bfs()
{
    fill_n(&dist[0][0], MAX * MAX, -1);
    queue< pair<int, int> > q;
    dist[sx][sy] = 0;
    q.push(make_pair(sx, sy));

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        cout << x << " " << y << "\n";

        if (x == tx && y == ty)
            return dist[x][y];
        
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M || dist[nx][ny] != -1)
                continue;
            
            if (is_possible(nx, ny))
            {
                dist[nx][ny] = dist[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    
    cin >> H >> W >> sx >> sy >> tx >> ty;
    sx -= 1;
    sy -= 1;
    tx -= 1;
    ty -= 1;

    cout << bfs() << "\n";

    return 0;
}
