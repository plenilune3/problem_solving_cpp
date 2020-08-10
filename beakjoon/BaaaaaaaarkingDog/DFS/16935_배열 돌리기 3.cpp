#include <iostream>

using namespace std;

const int MAX = 100;

int board[MAX][MAX];
int N, M, R;

void flip_vertical()
{
    int board_copy[MAX][MAX];

    for (int j = 0; j < M; j++)
        for (int i = 0; i < N; i++)
            board_copy[i][j] = board[(N - 1) - i][j];
    
    copy(&board_copy[0][0], &board_copy[0][0] + MAX * MAX, &board[0][0]);
}

void flip_horizon()
{
    int board_copy[MAX][MAX];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            board_copy[i][j] = board[i][(M - 1) - j];
    
    copy(&board_copy[0][0], &board_copy[0][0] + MAX * MAX, &board[0][0]);
}

void rotate_cw()
{
    int board_copy[MAX][MAX];

    int R = M, C = N;

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            board_copy[i][j] = board[N - 1 - j][i];
    
    swap(N, M);
    copy(&board_copy[0][0], &board_copy[0][0] + MAX * MAX, &board[0][0]);
}

void rotate_ccw()
{
    int board_copy[MAX][MAX];

    int R = M, C = N;

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            board_copy[i][j] = board[j][M - 1 - i];
    
    swap(N, M);
    copy(&board_copy[0][0], &board_copy[0][0] + MAX * MAX, &board[0][0]);
}

void calculate_cw()
{
    int board_copy[MAX][MAX];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int num = (i / (N / 2) * 2 + (j / (M / 2)));

            if (num == 0)
                board_copy[i][j + (M / 2)] = board[i][j];
            else if (num == 1)
                board_copy[i + (N / 2)][j] = board[i][j];
            else if (num == 3)
                board_copy[i][j - (M / 2)] = board[i][j];
            else
                board_copy[i - (N / 2)][j] = board[i][j];
        }
    }

    copy(&board_copy[0][0], &board_copy[0][0] + MAX * MAX, &board[0][0]);
}

void calculate_ccw()
{
    int board_copy[MAX][MAX];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int num = (i / (N / 2) * 2 + (j / (M / 2)));

            if (num == 0)
                board_copy[i + (N / 2)][j] = board[i][j];
            else if (num == 2)
                board_copy[i][j + (M / 2)] = board[i][j];
            else if (num == 3)
                board_copy[i - (N / 2)][j] = board[i][j];
            else
                board_copy[i][j - (M / 2)] = board[i][j];
        }
    }

    copy(&board_copy[0][0], &board_copy[0][0] + MAX * MAX, &board[0][0]);
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
    {
        int T;
        cin >> T;

        if (T == 1)
            flip_vertical();
        else if (T == 2)
            flip_horizon();
        else if (T == 3)
            rotate_cw();
        else if (T == 4)
            rotate_ccw();
        else if (T == 5)
            calculate_cw();
        else
            calculate_ccw();
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
