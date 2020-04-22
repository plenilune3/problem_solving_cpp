#include <iostream>

using namespace std;

const int MAX = 21;
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

int board[MAX][MAX];

int dice[7] = { 0 };
int dice_shape[4][3] =
{
    {0, 2, 0},
    {4, 1, 3},
    {0, 5, 0},
    {0, 6, 0}
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M, x, y, K;
    cin >> N >> M >> x >> y >> K;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    
    for (int k = 0; k < K; k++)
    {
        int command;
        cin >> command;
        int nx = x + dx[command];
        int ny = y + dy[command];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;
        
        x = nx;
        y = ny;

        int temp;

        if (command == 1)
        {
            temp = dice_shape[1][2];
            dice_shape[1][2] = dice_shape[1][1];
            dice_shape[1][1] = dice_shape[1][0];
            dice_shape[1][0] = dice_shape[3][1];
            dice_shape[3][1] = temp;
        }
        else if (command == 2)
        {
            temp = dice_shape[1][0];
            dice_shape[1][0] = dice_shape[1][1];
            dice_shape[1][1] = dice_shape[1][2];
            dice_shape[1][2] = dice_shape[3][1];
            dice_shape[3][1] = temp;
        }
        else if (command == 3)
        {
            temp = dice_shape[0][1];
            dice_shape[0][1] = dice_shape[1][1];
            dice_shape[1][1] = dice_shape[2][1];
            dice_shape[2][1] = dice_shape[3][1];
            dice_shape[3][1] = temp;
        }
        else if (command == 4)
        {
            temp = dice_shape[3][1];
            dice_shape[3][1] = dice_shape[2][1];
            dice_shape[2][1] = dice_shape[1][1];
            dice_shape[1][1] = dice_shape[0][1];
            dice_shape[0][1] = temp;
        }

        if (board[nx][ny] == 0)
            board[nx][ny] = dice[dice_shape[3][1]];
        else
        {
            dice[dice_shape[3][1]] = board[nx][ny];
            board[nx][ny] = 0;
        }

        cout << dice[dice_shape[1][1]] << "\n";
    }

    return 0;
}
