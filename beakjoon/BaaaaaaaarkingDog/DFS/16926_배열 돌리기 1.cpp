#include <iostream>

using namespace std;

const int MAX = 300;

int board[MAX][MAX];
int N, M, R;

void rotate()
{
    int R = N, C = M;
    int x = 0, y = 0;

    while (R > 1 && C > 1)
    {
        int temp = board[x][y];

        for (int i = y; i < y + C - 1; i++)
            board[x][i] = board[x][i + 1];
       
        for (int i = x; i < x + R - 1; i++)
            board[i][y + C - 1] = board[i + 1][y + C - 1];
        
        for (int i = y + C - 1; i > y; i--)
            board[x + R - 1][i] = board[x + R - 1][i - 1];
        
        for (int i = x + R - 1; i > x; i--)
            board[i][y] = board[i - 1][y];
        
        board[x + 1][y] = temp;
        
        R -= 2, C -= 2, x += 1, y += 1;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> R;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    
    for (int i = 0; i < R; i++)
        rotate();

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
