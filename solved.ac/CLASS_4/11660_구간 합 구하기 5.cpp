#include <iostream>

using namespace std;

const int MAX = (1 << 10) + 2;

int N, M, board[MAX][MAX], p[MAX][MAX];

void prefix_sum();

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    
    prefix_sum();

    while (M--)
    {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        cout << p[x2][y2] - (p[x1 - 1][y2] + p[x2][y1 - 1]) + p[x1 - 1][y1 - 1] << "\n";
    }

    return 0;
}

void prefix_sum()
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            p[i + 1][j + 1] = p[i + 1][j] + p[i][j + 1] - p[i][j] + board[i][j];
}
