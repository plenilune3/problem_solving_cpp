#include <iostream>

using namespace std;

const int MAX = 51;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int R, C, T;
int board[MAX][MAX];
pair<int, int> top, bottom;

void diffuse();
void clean_top(pair<int, int> top);
void clean_bottom(pair<int, int> bottom);

int main(int argc, char const *argv[])
{
    cin >> R >> C >> T;

    top = make_pair(-1, -1);

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == -1)
            {
                board[i][j] = 0;
                if (top.first == -1) top = make_pair(i, j);
                else bottom = make_pair(i, j);
            }
        }

    while (T--)
    {
        diffuse();
        clean_top(top);
        clean_bottom(bottom);
    }

    int answer = 0;

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            answer += board[i][j];
    
    cout << answer << "\n";

    return 0;
}

void diffuse()
{
    int board_c[MAX][MAX];
    fill_n(&board_c[0][0], MAX * MAX, 0);

    for (int x = 0; x < R; x++)
        for (int y = 0; y < C; y++)
        {
            board_c[x][y] += board[x][y];

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];

                if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                    continue;
                
                if ((nx == top.first && ny == top.second) || (nx == bottom.first && ny == bottom.second))
                    continue;
                
                board_c[nx][ny] += board[x][y] / 5;
                board_c[x][y] -= board[x][y] / 5;
            }
        }
    
    copy(&board_c[0][0], &board_c[0][0] + MAX * MAX, &board[0][0]);
}

void clean_top(pair<int, int> top)
{
    int x = top.first, y = top.second;

    for (int i = x; i > 0; i--)
        board[i][0] = board[i - 1][0];
    
    for (int i = 0; i < C - 1; i++)
        board[0][i] = board[0][i + 1];
    
    for (int i = 0; i < x; i++)
        board[i][C - 1] = board[i + 1][C - 1];
    
    for (int i = C - 1; i > 0; i--)
        board[x][i] = board[x][i - 1];
    
    board[x][0] = 0, board[x][1] = 0;
}

void clean_bottom(pair<int, int> bottom)
{
    int x = bottom.first, y = bottom.second;

    for (int i = x; i < R - 1; i++)
        board[i][0] = board[i + 1][0];
    
    for (int i = 0; i < C - 1; i++)
        board[R - 1][i] = board[R - 1][i + 1];
    
    for (int i = R - 1; i > x; i--)
        board[i][C - 1] = board[i - 1][C - 1];
    
    for (int i = C - 1; i > 0; i--)
        board[x][i] = board[x][i - 1];
    
    board[x][0] = 0, board[x][1] = 0;
}


