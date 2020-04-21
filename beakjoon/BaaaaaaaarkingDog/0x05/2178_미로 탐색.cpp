#include <cstdio>
#include <queue>

using namespace std;

const int MAX = 100;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m;
int maze[MAX][MAX] = { 0 };

int bfs(int x, int y)
{
    queue < pair <int, int> > q;
    q.push(make_pair(x, y));
    pair <int, int> c;

    while (!q.empty())
    {
        c = q.front();
        q.pop();

        if (c.first == n - 1 && c.second == m - 1)
            break;

        for (int i = 0; i < 4; i++)
        {
            int nx = c.first + dx[i];
            int ny = c.second + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (maze[nx][ny] == 1)
                {
                    q.push(make_pair(nx, ny));
                    maze[nx][ny] = maze[c.first][c.second] + 1;
                }
            }
        }
    }

    return maze[n-1][m-1];
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%1d", &maze[i][j]);

    int answer = bfs(0, 0);
    printf("%d\n", answer);
    
    return 0;
}
