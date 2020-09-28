#include <iostream>
#include <climits>
#include <cstdio>

using namespace std;

const int MAX = 32;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N, M, answer = INT_MAX;
char board[MAX][MAX];
bool visited[MAX][MAX];

void backtracking(int depth, int x, int y);

int main(int argc, char const *argv[])
{
    iostream::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int case_number = 0;

    while (cin >> N >> M)
    {
        fill_n(&visited[0][0], MAX * MAX, false);
        answer = INT_MAX;

        for (int i = 0; i < N + 2; i++)
            for (int j = 0; j < M + 2; j++)
            {
                if (i == 0 || i == N + 1 || j == 0 || j == M + 1)
                    board[i][j] = '*';
                else
                {
                    cin >> board[i][j];

                    if (board[i][j] == '*')
                        visited[i][j] = true;
                }
            }
        
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                if (board[i][j] != '*')
                {
                    visited[i][j] = true;
                    backtracking(0, i, j);
                    visited[i][j] = false;
                }
        
        if (answer == INT_MAX)
            answer = -1;

        cout << "Case " << ++case_number << ": " << answer << "\n";
    } 

    return 0;
}

bool can_move(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];

        if (board[nx][ny] != '*' && visited[nx][ny] == false)
            return true;
    }

    return false;
}

void get_next(int &x, int &y, int d)
{
    while (board[x + dx[d]][y + dy[d]] != '*' && visited[x + dx[d]][y + dy[d]] == false)
        x += dx[d], y += dy[d];
}

void move(int x, int y, int nx, int ny, int d, bool b)
{
    x = x + dx[d], y = y + dy[d];

    while (true)
    {
        visited[x][y] = b; 

        if (x == nx && y == ny)
            break;
        
        x += dx[d], y += dy[d];
    }
}

bool is_finished()
{
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            if (visited[i][j] == false)
                return false;

    return true;
}

void backtracking(int depth, int x, int y)
{
    if (can_move(x, y) == false || depth >= 1e6)
    {
        if (is_finished())
            answer = min(answer, depth);

        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x, ny = y;
        get_next(nx, ny, i);
        if (nx == x && ny == y) continue;

        move(x, y, nx, ny, i, true);
        backtracking(depth + 1, nx, ny);
        move(x, y, nx, ny, i, false);
    }
}

