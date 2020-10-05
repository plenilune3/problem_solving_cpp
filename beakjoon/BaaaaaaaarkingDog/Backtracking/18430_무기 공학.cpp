#include <iostream>

using namespace std;

const int MAX = 5;
const int dx[4][3] = { { 0, 0, 1 }, { -1, 0, 0 }, { -1, 0, 0 }, { 0, 0, 1 }};
const int dy[4][3] = { { -1, 0, 0 }, { 0, 0, -1 }, { 0, 0, 1 }, { 1, 0, 0 }};

int N, M, answer;
int board[MAX][MAX];
bool visited[MAX][MAX];

bool is_out_of_range(int x, int y);
bool is_possible(int x, int y, int k);
int get_sum(int x, int y, int k, bool b);
void backtracking(int depth, int result);

int main(int argc, char const *argv[])
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    
    backtracking(0, 0);

    cout << answer << "\n";

    return 0;
}

bool is_out_of_range(int x, int y)
{
    return x < 0 || x >= N || y < 0 || y >= M;
}

bool is_possible(int x, int y, int k)
{
    for (int i = 0; i < 3; i++)
    {
        int nx = x + dx[k][i], ny = y + dy[k][i];

        if (is_out_of_range(nx, ny) || visited[nx][ny])
            return false;
    }

    return true;
}

int get_sum(int x, int y, int k, bool b)
{
    int sum = board[x][y];

    for (int i = 0; i < 3; i++)
    {
        int nx = x + dx[k][i] , ny = y + dy[k][i];
        visited[nx][ny] = b;
        sum += board[nx][ny];
    }

    return sum;
}

void backtracking(int depth, int result)
{
    if (depth == N * M)
    {
        answer = max(answer, result);
        return;
    }

    int x = depth / M, y = depth % M;

    if (visited[x][y])
    {
        backtracking(depth + 1, result);
        return;
    }

    backtracking(depth + 1, result);

    for (int k = 0; k < 4; k++)
    {
        if (!is_possible(x, y, k))
            continue;
        
        int sum = get_sum(x, y, k, true);
        backtracking(depth + 1, result + sum);
        get_sum(x, y, k, false);
    }
}