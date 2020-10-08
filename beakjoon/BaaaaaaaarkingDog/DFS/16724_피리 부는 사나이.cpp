#include <iostream>

using namespace std;

const int MAX = 1e3 + 1;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N, M, number = 1;
int board[MAX][MAX];
int visited[MAX][MAX];

int find_cycle(int x, int y);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string row; cin >> row;

        for (int j = 0; j < M; j++)
        {
            if (row[j] == 'U') board[i][j] = 0;
            else if (row[j] == 'D') board[i][j] = 1;
            else if (row[j] == 'L') board[i][j] = 2;
            else board[i][j] = 3;
        }
    }

    for (int x = 0; x < N; x++)
        for (int y = 0; y < M; y++)
        {
            int k = find_cycle(x, y);

            if (k == number) number += 1;
        }

    int answer = number - 1;

    cout << answer << "\n";

    return 0;
}

int find_cycle(int x, int y)
{
    if (visited[x][y])
        return visited[x][y];
    
    visited[x][y] = number;

    int dir = board[x][y];
    int nx = x + dx[dir], ny = y + dy[dir];

    return visited[x][y] = find_cycle(nx, ny);
}
