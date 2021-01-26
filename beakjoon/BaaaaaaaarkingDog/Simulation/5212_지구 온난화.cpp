#include <iostream>

using namespace std;

const int MAX = 11;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int R, C;
char board[MAX][MAX];

void flood_();
bool is_out_of_range(int x, int y);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> R >> C;

    for (int i = 0; i < R; i++)
        cin >> board[i];
    
    flood_();

    int max_r = 0, min_r = MAX, max_c = 0, min_c = MAX;

    for (int r = 0; r < R; r++)
        for (int c = 0; c < C; c++)
            if (board[r][c] == 'X')
            {
                min_r = min(min_r, r);
                max_r = max(max_r, r);
                min_c = min(min_c, c);
                max_c = max(max_c, c);
            }

    for (int r = min_r; r <= max_r; r++)
    {
        for (int c = min_c; c <= max_c; c++)
            cout << board[r][c];
        cout << "\n";
    }

    return 0;
}

void flood_()
{
    char board_c[MAX][MAX];
    copy(&board[0][0], &board[0][0] + MAX * MAX, &board_c[0][0]);

    for (int x = 0; x < R; x++)
        for (int y = 0; y < C; y++)
        {
            if (board[x][y] == '.') continue;

            int count_water = 0;

            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d], ny = y + dy[d];

                if (is_out_of_range(nx, ny) || board_c[nx][ny] == '.')
                    count_water += 1;
            }

            if (count_water >= 3) board[x][y] = '.';
        }
}

bool is_out_of_range(int x, int y)
{
    return x < 0 || x >= R || y < 0 || y >= C;
}
