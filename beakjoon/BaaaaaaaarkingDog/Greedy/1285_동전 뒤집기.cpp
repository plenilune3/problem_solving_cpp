#include <iostream>

#define ROW true
#define COLUMN false

using namespace std;

const int MAX = 21;

int N, answer = MAX * MAX;
char board[MAX][MAX], board_c[MAX][MAX];

void flip_init(int k, char board[MAX][MAX]);
void flip(bool flag, int x, char board[MAX][MAX]);
int count_back(char board[MAX][MAX]);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
        
    for (int k = 0; k < (1 << N); k++)
    {
        copy(&board[0][0], &board[0][0] + MAX * MAX, &board_c[0][0]);
        flip_init(k, board_c);
        answer = min(answer, count_back(board_c));
    }

    cout << answer << "\n";

    return 0;
}

void flip_init(int k, char board[MAX][MAX])
{
    for (int x = 0; x < N; x++)
        if (k & (1 << x))
            flip(ROW, x, board);
}

void flip(bool flag, int x, char board[MAX][MAX])
{
    for (int i = 0; i < N; i++)
        if (flag)
            board[x][i] = board[x][i] == 'H' ? 'T' : 'H';
        else
            board[i][x] = board[i][x] == 'H' ? 'T' : 'H';
}

int count_back(char board[MAX][MAX])
{
    int result = 0;

    for (int y = 0; y < N; y++)
    {
        int T = 0, H = 0;
        for (int x = 0; x < N; x++)
        {
            if (board[x][y] == 'T')
                T += 1;
            else
                H += 1;
        }
        result += min(T, H);
    }

    return result;
}
