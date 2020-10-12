#include <iostream>

using namespace std;

const int MAX = 100;

int N, L;
int board[MAX][MAX];

void rotate(int board[MAX][MAX]);
int count_ramp(int board[MAX][MAX]);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> N >> L;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    
    int row = count_ramp(board);
    rotate(board);
    int col = count_ramp(board);

    int answer = row + col;

    cout << answer << "\n";
    
    return 0;
}

int count_ramp(int board[MAX][MAX])
{
    int ramp = 0;

    for (int i = 0; i < N; i++)
    {
        int length = 1;
        bool is_possible = true;

        for (int j = 1; j < N; j++)
        {
            int diff = board[i][j] - board[i][j - 1];

            if (diff == 0) length += 1;
            else if (diff == 1 && length >= L) length = 1;
            else if (diff == -1 && length >= 0) length = -L + 1;
            else
            {
                is_possible = false;
                break;
            }
        }

        if (is_possible && length >= 0) ramp += 1;
    }

    return ramp;
}

void rotate(int board[MAX][MAX])
{
    int board_c[MAX][MAX];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board_c[i][j] = board[N - 1 - j][i];

    copy(&board_c[0][0], &board_c[0][0] + MAX * MAX, &board[0][0]);
}
