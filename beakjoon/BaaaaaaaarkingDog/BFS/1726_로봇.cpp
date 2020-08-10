#include <iostream>
#include <queue>

using namespace std;

const int MAX = 102;
const int dx[] = { 0, 0, 0, 1, -1 };
const int dy[] = { 0, 1, -1, 0, 0 };

struct robot
{
    int x, y, dir;
};

int N, M;
bool board[MAX][MAX];
int dist[MAX][MAX][5];

robot make_robot(int x, int y, int d)
{
    robot t = { x, y, d };
    return t; 
}

int bfs(robot s, robot t)
{
    fill_n(&dist[0][0][5], MAX * MAX * 5, -1);
    queue<robot> q;
    dist[s.x][s.y][s.dir] = 0;
    q.push(s);

    while (!q.empty())
    {
        robot c = q.front(); q.pop();
        int x = c.x, y = c.y, d = c.dir;

        if (x == t.x && y == t.y && d == t.dir)
            return dist[x][y][d];
        
        if (d == 1 || d == 2)
        {
            for (int i = 3; i <= 4; i++)
                if (dist[x][y][i] == -1)
                {
                    dist[x][y][i] = dist[x][y][d] + 1;
                    q.push(make_robot(x, y, i));
                }
        }
        else
        {
            for (int i = 1; i <= 2; i++)
                if (dist[x][y][i] == -1)
                {
                    dist[x][y][i] = dist[x][y][d] + 1;
                    q.push(make_robot(x, y, i));
                }
        }

        for (int i = 1; i <= 3; i++)
        {
            int nx = x + dx[d] * i, ny = y + dy[d] * i;

            if (board[nx][ny])
                break;
            
            if (dist[nx][ny][d] == -1)
            {
                dist[nx][ny][d] = dist[x][y][d] + 1;
                q.push(make_robot(nx, ny, d));
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
                board[i][j] = true;
            else
                cin >> board[i][j];
        }
    
   
    robot s, t;

    cin >> s.x >> s.y >> s.dir;
    cin >> t.x >> t.y >> t.dir;

    cout << bfs(s, t) << "\n";

    return 0;
}
