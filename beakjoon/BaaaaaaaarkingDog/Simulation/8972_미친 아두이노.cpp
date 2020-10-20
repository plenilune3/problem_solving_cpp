#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 105;
const int dx[] = { 0, 1, 1, 1, 0, 0, 0, -1, -1, -1 };
const int dy[] = { 0, -1, 0, 1, -1, 0, 1, -1, 0, 1 };

int R, C, N;
int ix, iy;
char board[MAX][MAX];
char board_next[MAX][MAX];
queue< pair<int, int> > arduinos;
string movement;

bool move_I(int d);
bool move_R();

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> R >> C;

    for (int i = 0; i < R; i++)
    {
        cin >> board[i];

        for (int j = 0; j < C; j++)
            if (board[i][j] == 'I')
                ix = i, iy = j;
            else if (board[i][j] == 'R')
                arduinos.push(make_pair(i, j));
    }

    cin >> movement;
    N = (int) movement.size();

    bool is_gameover = false;
    int cnt = 0;

    for (int i = 0; i < N; i++)
    {
        fill_n(&board_next[0][0], MAX*MAX, '.');

        if (!move_I(movement[i] - '0') || !move_R())
        {
            is_gameover = true;
            cnt = i + 1;
            break;
        }

        for (int x = 0; x < R; x++)
            for (int y = 0; y < C; y++)
            {
                if (board_next[x][y] == 'X')
                    board[x][y] = '.';
                else if (board_next[x][y] == 'R')
                {
                    arduinos.push(make_pair(x, y));
                    board[x][y] = 'R';
                }
                else
                    board[x][y] = board_next[x][y];
            }
    }

    if (is_gameover)
        cout << "kraj " << cnt << "\n";
    else
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
                cout << board[i][j];
            cout << "\n";
        }

    return 0;
}

bool move_I(int d)
{
    int nx = ix + dx[d], ny = iy + dy[d];

    if (board[nx][ny] == 'R')
        return false;
    
    board_next[nx][ny] = 'I';
    ix = nx, iy = ny;

    return true;
}

bool move_R()
{
    while (!arduinos.empty())
    {
        int x = arduinos.front().first, y = arduinos.front().second;
        arduinos.pop();

        if (x < ix) x++;
        else if (x > ix) x--;
        if (y < iy) y++;
        else if (y > iy) y--;

        if (board_next[x][y] == 'I')
            return false;
        else if (board_next[x][y] == 'R')
            board_next[x][y] = 'X';
        else if (board_next[x][y] == '.')
            board_next[x][y] = 'R';
    }

    return true;
}
