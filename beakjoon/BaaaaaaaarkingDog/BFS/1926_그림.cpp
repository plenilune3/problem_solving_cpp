#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 502;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, m;
int c = 0;
int a = 0;
int ma = 0;
int painting[MAX][MAX];
bool visited[MAX][MAX] = {false};


void dfs(int depth, int x, int y)
{
    visited[x][y] = true;
    a++;

    for (int i = 0; i < 4; i++)
    {
        int nx, ny;
        nx = x + dx[i];
        ny = y + dy[i];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            if (visited[nx][ny] == false && painting[nx][ny] == 1)
                dfs(depth+ 1, nx, ny);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> painting[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == false && painting[i][j] == 1)
            {
                c++;
                a = 0;
                dfs(1, i, j);
                ma = max(ma, a);
            }
        }
    }

    cout << c << "\n";
    cout << ma << "\n";

    return 0;
}
