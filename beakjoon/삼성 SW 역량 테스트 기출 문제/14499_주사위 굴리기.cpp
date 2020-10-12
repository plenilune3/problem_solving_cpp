#include <iostream>

using namespace std;

const int MAX = 20;
const int dx[] = { 0, 0, 0, -1, 1 };
const int dy[] = { 0, 1, -1, 0, 0 };

int N, M, r, c, K;
int board[MAX][MAX];

int dice[4][3] = {
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 },
    { 0, 0, 0 }
};

void roll_dice(int k);
void east();
void west();
void north();
void south();

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> r >> c >> K;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    
    while (K--)
    {
        int k; cin >> k;

        int nr = r + dx[k], nc = c + dy[k];

        if (nr < 0 || nr >= N || nc < 0 || nc >= M)
            continue;
        
        r = nr, c = nc;
        
        roll_dice(k);

        if (board[r][c] == 0)
            board[r][c] = dice[3][1];
        else
        {
            dice[3][1] = board[r][c];
            board[r][c] = 0;
        }

        cout << dice[1][1] << "\n";
    }

    return 0;
}

void roll_dice(int k)
{
    if (k == 1) east();
    else if (k == 2) west();
    else if (k == 3) north();
    else south();
}

void east()
{
    int temp = dice[3][1];

    dice[3][1] = dice[1][0];
    dice[1][0] = dice[1][1];
    dice[1][1] = dice[1][2];
    dice[1][2] = temp;
}

void west()
{
    int temp = dice[3][1];

    dice[3][1] = dice[1][2];
    dice[1][2] = dice[1][1];
    dice[1][1] = dice[1][0];
    dice[1][0] = temp;
}

void north()
{
    int temp = dice[0][1];

    dice[0][1] = dice[1][1];
    dice[1][1] = dice[2][1];
    dice[2][1] = dice[3][1];
    dice[3][1] = temp;
}

void south()
{
    int temp = dice[0][1];

    dice[0][1] = dice[3][1];
    dice[3][1] = dice[2][1];
    dice[2][1] = dice[1][1];
    dice[1][1] = temp;
}
