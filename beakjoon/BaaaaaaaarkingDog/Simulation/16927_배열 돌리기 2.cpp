#include <iostream>

using namespace std;

const int MAX = 301;

int N, M, R, A[MAX][MAX];

void rotate(int N, int M, int R, int x, int y, int A[MAX][MAX]);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> R;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];
    
    rotate(N, M, R, 0, 0, A);
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << A[i][j] << " ";
        cout << "\n";
    }
    
    return 0;
}

void rotate(int N, int M, int R, int x, int y, int A[MAX][MAX])
{
    if (N <= 1 || M <= 1)
        return;

    int r = R % (2 * N + 2 * M - 4);

    while (r--)
    {
        int temp = A[x][y];

        for (int i = y; i < y + M - 1; i++)
            A[x][i] = A[x][i + 1];
        
        for (int i = y; i < x + N - 1; i++)
            A[i][y + M - 1] = A[i + 1][y + M - 1];
        
        for (int i = y + M - 1; i > y; i--)
            A[x + N - 1][i] = A[x + N - 1][i - 1];
        
        for (int i = x + N - 1; i > x; i--)
            A[i][y] = A[i - 1][y];
        
        A[x + 1][y] = temp;
    }

    rotate(N - 2, M - 2, R, x + 1, y + 1, A);
}