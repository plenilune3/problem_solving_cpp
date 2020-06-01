#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

const int MAX = 10;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

struct altair
{
    int x, y;
    bool ojak;
};

int N, M;
int board[MAX][MAX];
int dist[MAX][MAX][2];
vector< pair<int, int> > v;

bool check_cliff(int x, int y)
{
    int hcnt = 0, vcnt = 0;

    if (board[x][y] == 1)
        return true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue;
        
        if (board[nx][ny] == 0 && (i == 0 || i == 1))
            vcnt += 1;
        if (board[nx][ny] == 0 && (i == 2 || i == 3))
            hcnt += 1;
    }

    if (vcnt >= 1 && hcnt >= 1)
        return false;
    else
        return true;
}

int wait_until(int time, int M)
{
    int result = time;

    while (result % M != 0)
        result += 1;
    
    return result;
}

void bfs(int x, int y)
{
    fill_n(&dist[0][0][0], MAX * MAX * 2, INT_MAX);
    queue<altair> q;
    altair init = { x, y, false };
    dist[x][y][0] = 0;
    q.push(init);

    while(!q.empty())
    {
        altair c = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = c.x + dx[i], ny = c.y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;

            if (check_cliff(nx, ny) == false)
                continue;
            
            if (board[nx][ny] == 1)
            {
                if (dist[nx][ny][c.ojak] > dist[c.x][c.y][c.ojak] + 1)
                {
                    altair n = { nx, ny, c.ojak };
                    dist[nx][ny][c.ojak] = dist[c.x][c.y][c.ojak] + 1;
                    q.push(n);
                }
            }
            else if (board[nx][ny] == 0 && c.ojak == false && board[c.x][c.y] == 1)
            {
                int time = wait_until(dist[c.x][c.y][c.ojak] + 1, M);
                if (dist[nx][ny][1] > time)
                {
                    altair n = { nx, ny, true };
                    dist[nx][ny][1] = time;
                    q.push(n);
                }
            }
            else if (board[nx][ny] >= 2 && board[c.x][c.y] == 1)
            {
                int time = wait_until(dist[c.x][c.y][c.ojak] + 1, board[nx][ny]);
                if (dist[nx][ny][c.ojak] > time)
                {
                    altair n = { nx, ny, c.ojak };
                    dist[nx][ny][c.ojak] = time;
                    q.push(n);
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];

            if (board[i][j] != 1)
                v.push_back(make_pair(i, j));
        }

    bfs(0, 0);

    cout << min(dist[N-1][N-1][0], dist[N-1][N-1][1]) << "\n";

    return 0;
}
