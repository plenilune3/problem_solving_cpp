#include <iostream>

using namespace std;

const int MAX = 401;

int N;
char board[MAX][MAX];

void star(int d, int x, int y);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    star(N, 0, 0);

    int l = 4 * N - 3;

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < l; j++)
            cout << board[i][j];
        cout << "\n";
    }

    return 0;
}

void star(int d, int x, int y)
{
    if (d == 1)
    {
        board[x][y] = '*';
        return;
    }

    int l = 4 * d - 3;

    for (int i = x; i < x + l; i++)
        for (int j = y; j < y + l; j++)
            if (i == x || i == x + l - 1 || j == y || j == y + l - 1)
                board[i][j] = '*';
            else
                board[i][j] = ' ';
    
    star(d - 1, x + 2, y + 2);
}
