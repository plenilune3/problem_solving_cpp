#include <iostream>

using namespace std;

const int MAX = 252;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int R, C;
char A[MAX][MAX];
bool visited[MAX][MAX];

void dfs(int x, int y, int &o, int &v)
{
    visited[x][y] = true;

    if (A[x][y] == 'o')
        o += 1;
    else if (A[x][y] == 'v')
        v += 1;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 1 || nx > R || ny < 1 || ny > C || visited[nx][ny])
            continue;

        if (A[nx][ny] != '#')
            dfs(nx ,ny, o, v);
    }
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int sheep = 0, wolf = 0;

    cin >> R >> C;

    for (int i = 0; i < R + 2; i++)
        for (int j = 0; j < C + 2; j++)
        {
            if (i == 0 || j == 0 || i == R + 1 || j == C + 1)
                A[i][j] = '#';
            else
                cin >> A[i][j];
        }
    
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
        {

            int o = 0, v = 0;

            if (A[i][j] != '#' && visited[i][j] == false)
                dfs(i, j, o, v);
            
            if (o == 0 && v == 0)
                continue;
            else if (o > v)
                sheep += o;
            else
                wolf += v;
        }

    cout << sheep << " " << wolf << "\n";

    return 0;
}
