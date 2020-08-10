#include <iostream>
#include <string>
#include <queue>

using namespace std;

const int MAX = 52;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

struct log
{
    int cx, cy, tx, ty;
    bool shape_c, shape_t;
};

int N;
char board[MAX][MAX];
int dist[MAX][MAX][2];

bool is_possible(int x, int y)
{
    for (int i = x - 1; i <= x + 1; i++)
        for (int j = y - 1; j <= y + 1; j++)
            if (board[i][j] == '1')
                return false;
    
    return true;
}

void rotate(log &l)
{
    if (is_possible(l.cx, l.cy))
        l.shape_c = !l.shape_c;
}

int bfs(log l)
{
    fill_n(&dist[0][0][0], MAX * MAX * 2, -1);
    queue<log> q;
    dist[l.cx][l.cy][l.shape_c] = 0;
    q.push(l);

    while (!q.empty())
    {
        log n = q.front();
        q.pop();

        if (n.cx == n.tx && n.cy == n.ty && n.shape_c == n.shape_t)
            return dist[n.cx][n.cy][n.shape_c];
        
        if (is_possible(n.cx, n.cy))
        {
            if (dist[n.cx][n.cy][!n.shape_c] == -1)
            {
                dist[n.cx][n.cy][!n.shape_c] = dist[n.cx][n.cy][n.shape_c] + 1;
                log nn = { n.cx, n.cy, n.tx, n.ty, !n.shape_c, n.shape_t };
                q.push(nn);
            }
        }

        for (int i = 0; i < 4; i++)
        {
            int ax, ay, bx, by;
            int nx = n.cx + dx[i], ny = n.cy + dy[i];

            if (n.shape_c == false)
                ax = nx - 1, ay = ny, bx = nx + 1, by = ny;
            else
                ax = nx, ay = ny - 1, bx = nx, by = ny + 1;
            
            if (board[nx][ny] == '1' || board[ax][ay] == '1' || board[bx][by] == '1')
                continue;
            
            if (dist[nx][ny][n.shape_c] == -1)
            {
                dist[nx][ny][n.shape_c] = dist[n.cx][n.cy][n.shape_c] + 1;
                log nn = { nx, ny, n.tx, n.ty, n.shape_c, n.shape_t };
                q.push(nn);
            }
        }
    }
    
    return 0;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    log l;
    pair<int, int> c[3], t[3];
    cin >> N;

    int c_index = 0, t_index = 0;

    for (int i = 1; i <= N; i++)
    {
        string str;

        cin >> str;

        for (int j = 0; j < N; j++)
        {
            if (str[j] == 'B')
            {
                c[c_index].first = i, c[c_index].second = j + 1;
                str[j] = '0';
                c_index += 1;
            }
            else if (str[j] == 'E')
            {
                t[t_index].first = i, t[t_index].second = j + 1;
                str[j] = '0';
                t_index += 1;
            }

            board[i][j + 1] = str[j];
        }
    }

    for (int i = 0; i < N + 2; i++)
        for (int j = 0; j < N + 2; j++)
            if (i == 0 || j == 0 || i == N + 1 || j == N + 1)
                board[i][j] = '1';
    
    l.cx = c[1].first, l.cy = c[1].second;
    l.tx = t[1].first, l.ty = t[1].second;

    if (c[1].second == c[2].second)
        l.shape_c = false;
    else
        l.shape_c = true;
    
    if (t[1].second == t[2].second)
        l.shape_t = false;
    else
        l.shape_t = true;
    
    cout << bfs(l) << "\n";

    return 0;
}
