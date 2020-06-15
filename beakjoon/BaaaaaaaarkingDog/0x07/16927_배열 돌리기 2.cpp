#include <iostream>

using namespace std;

const int MAX = 300;

int board[MAX][MAX];
int N, M, R;

void rotate(int S)
{
    for (int s = 0; s < S; s++)
    {
        int x = s, y = s;
        int A = N - s, B = M - s;
        int r = R % (2 * (A - x) + 2 * (B - y) - 4);

        while (r--)
        {
            int temp = board[x][y];

            for (int i = y; i < B - 1; i++)
                board[x][i] = board[x][i + 1];
        
            for (int i = x; i < A - 1; i++)
                board[i][B - 1] = board[i + 1][B - 1];
            
            for (int i = B - 1; i > y; i--)
                board[A - 1][i] = board[A - 1][i - 1];
            
            for (int i = A - 1; i > x; i--)
                board[i][y] = board[i - 1][y];
            
            board[x + 1][y] = temp;
        }
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
    
    int S = min(N, M) / 2;
    rotate(S);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
