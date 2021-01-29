#include <iostream>

using namespace std;

const int MAX = 21;

int N;
int board[MAX][MAX];

int divide_(int sx, int sy, int ex, int ey, int d);
bool is_cut(int sx, int sy, int ex, int ey, int x, int y, int d);
bool is_possible(int sx, int sy, int ex, int ey);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    
    int answer = divide_(0, 0, N, N, 1) + divide_(0, 0, N, N, 0);

    if (answer)
        cout << answer << "\n";
    else
        cout << -1 << "\n";

    return 0;
}

int divide_(int sx, int sy, int ex, int ey, int d)
{
    if (is_possible(sx, sy, ex, ey))
        return 1;

    int ret = 0;

    for (int x = sx; x < ex; x++)
        for (int y = sy; y < ey; y++)
            if (board[x][y] == 1)
            {
                if (d == 0 && is_cut(sx, sy, ex, ey, x, y, d))
                    ret += divide_(sx, sy, x, ey, 1) * divide_(x + 1, sy, ex, ey, 1);
                if (d == 1 && is_cut(sx, sy, ex, ey, x, y, d))
                    ret += divide_(sx, sy, ex, y, 0) * divide_(sx, y + 1, ex, ey, 0);
            }
    
    return ret;
}

bool is_cut(int sx, int sy, int ex, int ey, int x, int y, int d)
{
    if (d == 0)
    {
        for (int i = sy; i < ey; i++)
            if (board[x][i] == 2) return false;
    }

    else if (d == 1)
    {
        for (int i = sx; i < ex; i++)
            if (board[i][y] == 2) return false;
    }

    return true;
}

bool is_possible(int sx, int sy, int ex, int ey)
{
    int crystal = 0, impurity = 0;

    for (int i = sx; i < ex; i++)
        for (int j = sy; j < ey; j++)
            if (board[i][j] == 1)
                impurity += 1;
            else if (board[i][j] == 2)
                crystal += 1;
    
    return crystal == 1 && impurity == 0;
}
