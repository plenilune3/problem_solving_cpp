#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 100;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char po[MAX][MAX];
char pw[MAX][MAX];
bool visited[MAX][MAX] = { false };
int N, a = 0, b = 0;

void dfs(char c, int x, int y, char painting[][MAX])
{
    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue;
        
        if (visited[nx][ny] == false && painting[nx][ny] == c)
            dfs(c, nx, ny, painting);
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            scanf("%1s", &po[i][j]);

            if (po[i][j] == 'R' || po[i][j] == 'G')
                pw[i][j] = 'Z';
            else
                pw[i][j] = po[i][j];

        }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j] == false)
            {
                if (po[i][j] == 'R')
                {
                    dfs('R', i, j, po);
                    a++;
                }
                else if (po[i][j] == 'G')
                {
                    a++;
                    dfs('G', i, j, po);
                }
                else
                {
                    a++;
                    dfs('B', i, j, po);
                }
            }
        }
    }

    fill_n(&visited[0][0], MAX*MAX, false);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j] == false)
            {
                if (pw[i][j] == 'Z')
                {
                    dfs('Z', i, j, pw);
                    b++;
                }
                else
                {
                    dfs('B', i, j, pw);
                    b++;
                }
            }
        }
    }

    printf("%d %d\n", a, b);

    return 0;
}
