#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 51;

bool board[MAX][MAX];
int S, N, K, R1, C1, R2, C2;

bool is_out_of_range(int r1, int r2, int c1, int c2);
bool is_black(int x);
void fractal(int x, int y, int t, bool c);

int main(int argc, char const *argv[])
{
    cin >> S >> N >> K >> R1 >> R2 >> C1 >> C2;

    fractal(0, 0, pow(N, S), 0);

    for (int i = R1; i <= R2; i++)
    {
        for (int j = C1; j <= C2; j++)
            cout << board[i - R1][j - C1];
        cout << "\n";
    }

    return 0;
}

bool is_out_of_range(int r1, int r2, int c1, int c2)
{
    if (r1 > R2 || r2 < R1 || c1 > C2 || c2 < C1)
        return true;
    
    return false;
}

bool is_black(int x)
{
    return !((x < (N - K) / 2) || ((N - 1 - x) < (N - K) / 2));
}

void fractal(int x, int y, int l, bool c)
{
    if (is_out_of_range(x*l, x*l+l-1, y*l, y*l+l-1))
        return;

    if (l == 1)
    {
        board[x - R1][y - C1] = c;
        return;
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            int nc = c ? 1 : is_black(i) && is_black(j);
            fractal(x * N + i, y * N + j, l / N, nc);
        }
}
