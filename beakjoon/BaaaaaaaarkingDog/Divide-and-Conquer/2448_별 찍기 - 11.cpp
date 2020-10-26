#include <iostream>

using namespace std;

const int MAX = 3 * (1 << 10);

int N;
char board[MAX][MAX * 2];

void star(int x, int y, int l);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < 2 * N - 1; j++)
            board[i][j] = ' ';
    
    int x = 0, y = (2 * N - 1) / 2;
    star(x, y, N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 2 * N - 1; j++)
            cout << board[i][j];
        cout << "\n";
    }
    
    return 0;
}

void star(int x, int y, int l)
{
    if (l == 3)
    {
        for (int i = 0; i < 3; i++)
            for (int j = y - i; j <= y + i; j++)
                board[x + i][j] = '*';
        
        board[x + 1][y] = ' ';

        return;
    }

    int nl = l / 2;

    star(x, y, nl);
    star(x + nl, y - nl, nl);
    star(x + nl, y + nl, nl);
}
