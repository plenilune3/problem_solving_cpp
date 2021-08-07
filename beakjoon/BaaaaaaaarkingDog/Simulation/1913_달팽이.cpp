#include <iostream>

using namespace std;

const int MAX = 1e3;

int N, T, ax, ay;
int board[MAX][MAX];

void is_target(int x, int y);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> T;

    int x = N / 2, y = N / 2;
    int k = 0, d = 0, sw = 1;
    board[x][y] = ++k;
    is_target(x, y);

    while (true)
    {
        d += 1;
        
        for (int i = 0; i < d; i++)
        {
            x -= sw;
            board[x][y] = ++k;
            is_target(x, y);

            if (k >= N * N) break;
        }

        if (k >= N * N) break;

        for (int i = 0; i < d; i++)
        {
            y += sw;
            board[x][y] = ++k;
            is_target(x, y);
        }

        sw *= -1;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }

    cout << ax << " " << ay << "\n";

    return 0;
}

void is_target(int x, int y)
{
    if (board[x][y] == T)
        ax = x + 1, ay = y + 1;
}