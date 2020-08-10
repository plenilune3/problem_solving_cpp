#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 22;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

struct coin
{
    int a, b, c, d, depth;
};

int N, M;
char board[MAX][MAX];

void move(int &x, int &y, int i)
{
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (board[nx][ny] != '#')
        x = nx, y = ny;
}

int bfs(vector<int> c)
{
    bool visited[MAX][MAX][MAX][MAX];
    fill_n(&visited[0][0][0][0], MAX * MAX * MAX * MAX, false);
    queue<coin> q;
    coin init = { c[0], c[1], c[2], c[3], 0 };
    visited[c[0]][c[1]][c[2]][c[3]] = true;
    q.push(init);

    int result = -1;

    while (!q.empty())
    {
        coin t = q.front();
        q.pop();

        if (t.depth > 10)
            break;

        if (board[t.a][t.b] == 'x' || board[t.c][t.d] == 'x')
        {
            result = t.depth;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int a = t.a, b = t.b, c = t.c, d = t.d;

            move(a, b, i);
            move(c, d, i);

            if ((board[a][b] == 'x' && board[c][d] == 'x') || visited[a][b][c][d])
                continue;
            
            visited[a][b][c][d] = true;
            coin nt = { a, b, c, d, t.depth + 1 };
            q.push(nt);
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    vector<int> c;
    cin >> N >> M;

    for (int i = 0; i < N + 2; i++)
        for (int j = 0; j < M + 2; j++)
        {
            if (i == 0 || j == 0 || i == N + 1 || j == M + 1)
                board[i][j] = 'x';
            else
            {
                cin >> board[i][j];

                if (board[i][j] == 'o')
                {
                    c.push_back(i);
                    c.push_back(j);
                }
            }
        }
    
    cout << bfs(c) << "\n";

    return 0;
}
