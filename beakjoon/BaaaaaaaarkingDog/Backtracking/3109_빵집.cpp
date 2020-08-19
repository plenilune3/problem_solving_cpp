#include <iostream>

using namespace std;

const int ROW = 10000;
const int COLUMN = 500;
const int dx[] = { -1, 0, 1 };
const int dy[] = { 1, 1, 1 };

int R, C;
char board[ROW][COLUMN];
bool visited[ROW][COLUMN];

bool install_pipe(int x, int y);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int answer = 0;

    cin >> R >> C;

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> board[i][j];
    
    for (int i = 0; i < R; i++)
        answer += install_pipe(i, 0);
    
    cout << answer << "\n";

    return 0;
}

bool install_pipe(int x, int y)
{
    visited[x][y] = true;

    if (y == C - 1)
        return true;
    
    for (int i = 0; i < 3; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 0 || nx >= R || ny < 0 || ny >= C)
            continue;
        
        if (visited[nx][ny] || board[nx][ny] == 'x')
            continue;
        
        bool is_possible = install_pipe(nx, ny);

        if (is_possible)
            return is_possible;
    }

    return false;
}
