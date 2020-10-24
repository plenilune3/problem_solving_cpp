#include <iostream>

using namespace std;

const int MAX = 2187;

int N;
char board[MAX][MAX];

void star(int x, int y, int length, char c);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    star(0, 0, N, '*');

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << board[i][j];
        cout << "\n";
    }
    
    return 0;
}

void star(int x, int y, int length, char c)
{
    if (length == 1)
    {
        board[x][y] = c;
        return;
    }

    int l = length / 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
        {
            int nx = x + (l * i), ny = y + (l * j);

            if (i != 1 || j != 1) star(nx, ny, l, c);
            else star(nx, ny, l, ' ');
        }
}