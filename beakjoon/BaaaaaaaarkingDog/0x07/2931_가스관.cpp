#include <iostream>

using namespace std;

const int MAX = 25;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int R, C;
int mx, my, zx, zy;
char pipeline[MAX][MAX];
bool visited[MAX][MAX];
int ax, ay;
char answer;

void dfs(int x, int y, char pipe)
{
    visited[x][y] = true;

    if (x == zx && y == zy)
    {
        ax = x, ay = y, answer = pipe;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 0 || nx >= R || ny < 0 || ny >= C || visited[nx][ny])
            continue;
        
        

    }
}

int main(int argc, char const *argv[])
{
    cin >> R >> C;

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            cin >> pipeline[i][j];

            if (pipeline[i][j] == 'Z')
                pipeline[i][j] = '.', zx = i, zy = j;
            else if (pipeline[i][j] == 'M')
                pipeline[i][j] = '.', mx = i, my = j;
        }
    
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            cout << pipeline[i][j];
        cout << "\n";
    }

    return 0;
}
