#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1002;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N, M, H, W;
int sx, sy, tx, ty;
bool board[MAX][MAX];
int dist[MAX][MAX];

bool is_possible(int x, int y)
{
    if (x + (H - 1) > N || y + (W - 1) > M)
        return false;
    
    for (int i = 0; i < H; i++)
        if (board[x + i][y])
            return false;
    
    for (int i = 0; i < H; i++)
        if (board[x + i][y + (W - 1)])
            return false;
    
    for (int i = 0; i < W; i++)
        if (board[x][y + i])
            return false;
    
    for (int i = 0; i < W; i++)
        if (board[x + (H - 1)][y + i])
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

        if (x == tx && y == ty)
            return dist[x][y];
        
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (board[nx][ny] || dist[nx][ny] != -1)
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

    for (int i = 0; i < N + 2; i++)
        for (int j = 0; j < M + 2; j++)
        {
            if (i == 0 || j == 0 || i == N + 1 || j == M + 1)
                board[i][j] = 1;
            else
                cin >> board[i][j];
        }
    
    cin >> H >> W >> sx >> sy >> tx >> ty;

    cout << bfs() << "\n";

    return 0;
}
