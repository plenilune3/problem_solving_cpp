#include <iostream>

using namespace std;

const int MAX = 200;

struct bomb
{
    char c;
    int t;
};

int R, C, N;
bomb board[MAX][MAX];

void time_cnt()
{
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (board[i][j].c == 'O')
                board[i][j].t += 1;
}

void explode()
{
    const int dx[] = { -1, 1, 0, 0 };
    const int dy[] = { 0, 0, -1, 1 };

    bomb board_copy[MAX][MAX];
    copy(&board[0][0], &board[0][0] + MAX * MAX, &board_copy[0][0]);

    for (int x = 0; x < R; x++)
        for (int y = 0; y < C; y++)
            if (board[x][y].c == 'O' && board[x][y].t == 3)
            {
                board_copy[x][y].c = '.';

                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx < 0 || nx >= R || ny < 0 || ny >= C || board[nx][ny].c == '.')
                        continue;
                    
                    board_copy[nx][ny].c = '.';
                    board_copy[nx][ny].t = 0;
                }
            }
    
    copy(&board_copy[0][0], &board_copy[0][0] + MAX * MAX, &board[0][0]);
}

void print()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            cout << board[i][j].c;
        cout << "\n";
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> R >> C >> N;

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            cin >> board[i][j].c;

            board[i][j].t = 0;
        }

    N = N - 1;
    time_cnt();

    while (true)
    {
        if (N-- == 0)
            break;
        
        time_cnt();
        
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                if (board[i][j].c == '.')
                {
                    board[i][j].c = 'O';
                    board[i][j].t = 0;
                }

        if (N-- == 0)
            break;

        time_cnt();
        explode();
    }

    print();

    return 0;
}
