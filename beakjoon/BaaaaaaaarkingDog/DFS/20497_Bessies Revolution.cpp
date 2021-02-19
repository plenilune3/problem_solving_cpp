#include <iostream>

using namespace std;

const int MAX = 11;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N, answer;
char board[MAX][MAX];
bool visited[MAX][MAX];

void dfs(int x, int y);
int count_(int x, int y);
bool is_out_of_range(int x, int y);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> board[i];

        for (int j = 0; j < N; j++)
            if (board[i][j] == 'S')
                board[i][j] = '@';
    }
    
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
        {
            if (board[x][y] == '@') continue;

            fill_n(&visited[0][0], MAX * MAX, false);

            board[x][y] = '@';
            int c = count_(x, y);
            board[x][y] = '.';

            if (c >= 2) answer += 1;
        }
    
    cout << answer << "\n";

    return 0;
}

int count_(int x, int y)
{
    int result = 0;

    for (int d = 0; d < 4; d++)
    {
        int nx = x + dx[d], ny = y + dy[d];

        if (is_out_of_range(nx, ny) || visited[nx][ny]) continue;

        if (board[nx][ny] == '@') continue;

        result += 1;
        dfs(nx, ny);
    }

    return result;
}

void dfs(int x, int y)
{
    visited[x][y] = true;

    for (int d = 0; d < 4; d++)
    {
        int nx = x + dx[d], ny = y + dy[d];

        if (is_out_of_range(nx, ny) || visited[nx][ny]) continue;

        if (board[nx][ny] == '@') continue;

        dfs(nx, ny);
    }
}

bool is_out_of_range(int x, int y)
{
    return x < 0 || x >= N || y < 0 || y >= N;
}