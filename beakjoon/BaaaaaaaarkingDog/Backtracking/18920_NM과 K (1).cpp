#include <iostream>
#include <climits>

using namespace std;

const int MAX = 10;
const int dx[] = { 0, -1, 1, 0, 0 };
const int dy[] = { 0, 0, 0, -1, 1 };

int N, M, K, answer = INT_MIN;
int board[MAX][MAX];
bool visited[MAX][MAX];

bool is_possible(int x, int y);
void combinations(int depth, int index, int sum);

int main(int argc, char const *argv[])
{
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    
    combinations(0, 0, 0);

    cout << answer << "\n";

    return 0;
}

bool is_possible(int x, int y)
{
    for (int i = 0; i < 5; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;
        
        if (visited[nx][ny])
            return false;
    }

    return true;
}

void combinations(int depth, int index, int sum)
{
    if (depth == K)
    {
        answer = max(answer, sum);
        return;
    }

    for (int i = index; i < N * M; i++)
    {
        int x = i / M, y = i % M;

        if (!is_possible(x, y))
            continue;
        
        visited[x][y] = true;
        combinations(depth + 1, i, sum + board[x][y]);
        visited[x][y] = false;
    }
}

