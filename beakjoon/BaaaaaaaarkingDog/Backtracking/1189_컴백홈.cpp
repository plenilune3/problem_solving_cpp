#include <iostream>

using namespace std;

const int MAX = 5;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int R, C, K, answer;
char board[MAX][MAX];
bool visited[MAX][MAX];

bool is_out_of_range(int x, int y);
void backtracking(int depth, int x, int y);

int main(int argc, char const *argv[])
{
    cin >> R >> C >> K;

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> board[i][j];
    
    visited[R - 1][0] = true;
    backtracking(1, R - 1, 0);
    visited[R - 1][0] = false;

    cout << answer << "\n";

    return 0;
}

bool is_out_of_range(int x, int y)
{
    return x < 0 || x >= R || y < 0 || y >= C;
}

void backtracking(int depth, int x, int y)
{
    if (depth == K)
    {
        if (x == 0 && y == C - 1)
            answer += 1;

        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];

        if (is_out_of_range(nx, ny) || visited[nx][ny])
            continue;
        
        if (board[nx][ny] == 'T')
            continue;
        
        visited[nx][ny] = true;
        backtracking(depth + 1, nx, ny);
        visited[nx][ny]= false;
    }
}

