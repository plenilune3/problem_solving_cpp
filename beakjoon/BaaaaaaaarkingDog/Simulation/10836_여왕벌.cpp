#include <iostream>

using namespace std;

const int MAX = 700;

int M, N;
int board[MAX][MAX];
int border[2 * MAX - 1];

void grow(int a, int b, int c);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    fill_n(&border[0], 2 * MAX - 1, 1);

    cin >> M >> N;

    while (N--)
    {
        int a, b, c; cin >> a >> b >> c;
        grow(a, b, c);
    }

    int pos = 0;

    for (int i = M - 1; i >= 0; i--)
        board[i][0] = border[pos++];
    
    for (int i = 1; i < M; i++)
        board[0][i] = border[pos++];
    
    for (int i = 1; i < M; i++)
        for (int j = 1; j < M; j++)
            board[i][j] = board[i - 1][j];

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }

    return 0;
}

void grow(int a, int b, int c)
{
    for (int i = a; i < a + b; i++)
        border[i] += 1;
    for (int i = a + b; i < 2 * M - 1; i++)
        border[i] += 2;
}
