#include <iostream>

using namespace std;

const int MAX = 51;
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

int N, M;
bool board[MAX][MAX];
bool visited[MAX][MAX];

int get_next_dir(int x, int y, int d);

int main(int argc, char const *argv[])
{
    int x, y, d;

    cin >> N >> M;
    cin >> x >> y >> d;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    int clean = 0;

    while (true)
    {
        visited[x][y] = true;
        clean += 1;

        int nd = get_next_dir(x, y, d);

        if (nd == -1)
        {
            nd = (d + 2) % 4;

            int nx = x + dx[nd], ny = y + dy[nd];

            if (board[nx][ny])
                break;
            else
            {
                clean -= 1;
                x = nx, y = ny, d = d;
            }
        }
        else
            d = nd, x += dx[d], y += dy[d];
    }

    cout << clean << "\n";

    return 0;
}

int get_next_dir(int x, int y, int d)
{
    for (int i = 0; i < 4; i++)
    {
        d = (d + 3) % 4;

        int nx = x + dx[d], ny = y + dy[d];

        if (board[nx][ny] || visited[nx][ny])
            continue;

        return d;
    }

    return -1;
}

