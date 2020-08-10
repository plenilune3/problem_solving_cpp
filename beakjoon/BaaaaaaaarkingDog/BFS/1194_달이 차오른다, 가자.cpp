#include <iostream>
#include <queue>
#include <string>

using namespace std;

const int MAX = 52;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

struct person
{
    int x, y, key, depth;
};

int N, M;
char board[MAX][MAX];
bool visited[MAX][MAX][64];

person make_person(int x, int y, int key, int depth)
{
    person p = { x, y, key, depth };
    return p;
}

int bfs(int sx, int sy)
{
    fill_n(&visited[0][0][0], MAX * MAX * 64, false);
    queue< person > q;
    visited[sx][sy][0] = true;
    q.push(make_person(sx, sy, 0, 0));

    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y, key = q.front().key, depth = q.front().depth; q.pop();

        if (board[x][y] == '1')
            return depth;
        
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (board[nx][ny] == '#' || visited[nx][ny][key])
                continue;
            
            person p;

            if ((board[nx][ny] >= 'A') && (board[nx][ny] <= 'Z') && (key & (1 << (board[nx][ny] - 'A'))))
            {
                p.x = nx, p.y = ny, p.key = key, p.depth = depth + 1;
                visited[nx][ny][key] = true;
                q.push(p);
            }
            
            if ((board[nx][ny] >= 'a') && (board[nx][ny] <= 'z'))
            {
                int nkey = key | (1 << (board[nx][ny] - 'a'));
                p.x = nx, p.y = ny, p.key = nkey, p.depth = depth + 1;
                visited[nx][ny][nkey] = true;
                q.push(p);
            }

            if (board[nx][ny] == '.' || board[nx][ny] == '1')
            {
                p.x = nx, p.y = ny, p.key = key, p.depth = depth + 1;
                visited[nx][ny][key] = true;
                q.push(p);
            }
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int sx, sy;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        string str;
        cin >> str;

        for (int j = 1; j <= M; j++)
        {
            board[i][j] = str[j - 1];

            if (board[i][j] == '0')
            {
                board[i][j] = '.';
                sx = i, sy = j;
            }
        }
    }

    for (int i = 0; i < N + 2; i++)
        for (int j = 0; j < M + 2; j++)
            if (i == 0 || j == 0 || i == N + 1 || j == M + 1)
                board[i][j] = '#';

    cout << bfs(sx, sy) << "\n";

    return 0;
}
