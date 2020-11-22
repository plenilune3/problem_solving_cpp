#include <iostream>

using namespace std;

const int MAX = (1 << 10) + 1;

int N;
char board[MAX][MAX];

void star(int x, int y, int l);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    int length = 1 << N;
    fill_n(&board[0][0], MAX * MAX, ' ');
    star(length - 1, 0, length);

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length - i; j++)
            cout << board[i][j];
        cout << "\n";
    }

    return 0;
}

void star(int x, int y, int l)
{
    if (l == 0)
    {
        board[x][y] = '*';
        return;
    }

    star(x, y, l / 2);
    star(x - (l / 2), y, l / 2);
    star(x - (l / 2), y + (l / 2), l / 2);
}