#include <iostream>

using namespace std;

const int MAX = 51;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N, M, sx, sy;
char board[MAX][MAX];
bool visited[MAX][MAX], cycle[MAX][MAX];
bool is_cycle;

void dfs(int depth, int x, int y, int dir);

int main(int argc, char const *argv[])
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> board[i];
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!visited[i][j])
                dfs(0, i, j, -1);

            if (is_cycle) break;
        }
        
        if (is_cycle) break;
    }

    if (is_cycle)
        cout << "Yes" << "\n";
    else
        cout << "No" << "\n";
    
    return 0;
}

void dfs(int depth, int x, int y, int dir)
{
    if (is_cycle) return;

    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;
        
        if (dir + i == 1 || dir + i == 5 || board[x][y] != board[nx][ny])
            continue;

        if (visited[nx][ny])
        {
            is_cycle = true;
            break;
        }
        
        dfs(depth + 1, nx, ny, i);
    }
}
