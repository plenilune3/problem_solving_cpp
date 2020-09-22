#include <iostream>

using namespace std;

const int MAX = 20;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N, M, answer;
char board[MAX][MAX];
bool alpha[26];

void backtracking(int depth, int x, int y);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    
    alpha[board[0][0] - 'A'] = true;
    backtracking(1, 0, 0);
    alpha[board[0][0] - 'A'] = false;

    cout << answer << "\n";

    return 0;
}

void backtracking(int depth, int x, int y)
{
    answer = max(answer, depth);

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;
        
        if (alpha[board[nx][ny] - 'A'])
            continue;
        
        alpha[board[nx][ny] - 'A'] = true;
        backtracking(depth + 1, nx, ny);
        alpha[board[nx][ny] - 'A'] = false;
    }
}
