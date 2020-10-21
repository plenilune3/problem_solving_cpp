#include <iostream>

using namespace std;

const int MAX = 51;

int N, M, answer = MAX * MAX;
char board[MAX][MAX];

bool is_possible(int x, int y);
int calculate_change(char board[8][8]);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> board[i];
    
    for (int x = 0; x < N; x++)
        for (int y = 0; y < M; y++)
        {
            if (!is_possible(x, y))
                continue;
            
            char board_c[8][8];

            for (int i = x; i < x + 8; i++)
                for (int j = y; j < y + 8; j++)
                    board_c[i - x][j - y] = board[i][j];

            answer = min(answer, calculate_change(board_c));
        }

    cout << answer << "\n";

    return 0;
}

bool is_possible(int x, int y)
{
    if (x + 8 > N || y + 8 > M)
        return false;
    
    return true;
}

int calculate_change(char board[8][8])
{
    int W = 0, B = 0;

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            if (((i + j) % 2 == 0 && board[i][j] != 'W') || ((i + j) % 2 != 0 && board[i][j] != 'B'))
                W += 1;
            if (((i + j) % 2 == 0 && board[i][j] != 'B') || ((i + j) % 2 != 0 && board[i][j] != 'W'))
                B += 1;
        }
    
    return min(W, B);
}
