#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 200;

struct monkey
{
    int x;
    int y;
    int k;
    int count;
};

int dkx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dky[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int K, W, H;
bool board[MAX][MAX];

int bfs(monkey m)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    queue<monkey> q;
    bool visited[MAX][MAX][31];
    fill_n(&visited[0][0][0], MAX*MAX*31, false);
    visited[0][0][0] = true;
    q.push(m);

    while (!q.empty())
    {
        monkey c = q.front();
        q.pop();

        if (c.x == H - 1 && c.y == W - 1)
            return c.count;

        for (int i = 0; i < 4; i++)
        {
            int nx = c.x + dx[i];
            int ny = c.y + dy[i];

            if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                continue;
            
            if (board[nx][ny] == 0 && visited[nx][ny][c.k] == false)
            {
                visited[nx][ny][c.k] = true;
                q.push({nx, ny, c.k, c.count + 1});
            }
        }
        
        if (c.k > 0)
        {
            for (int i = 0; i < 8; i++)
            {
                int nx = c.x + dkx[i];
                int ny = c.y + dky[i];

                if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                    continue;
                
                if (board[nx][ny] == 0 && visited[nx][ny][c.k - 1] == false)
                {
                    visited[nx][ny][c.k - 1] = true;
                    q.push({nx, ny, c.k - 1, c.count + 1});
                }
            }
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    cin >> K;
    cin >> W >> H;

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> board[i][j];

    monkey m = {0, 0, K, 0};
    
    int answer = bfs(m);

    cout << answer << "\n";

    return 0;
}
