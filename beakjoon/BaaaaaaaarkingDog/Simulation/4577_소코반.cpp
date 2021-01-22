#include <iostream>

using namespace std;

const int MAX = 16;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int R, C;
char board[MAX][MAX], board_c[MAX][MAX];
string cmd;

bool is_wall(int x, int y);
bool is_box(int x, int y);
bool is_complete();
void move_(int nx, int ny);
void push_(int nx, int ny, int nnx, int nny);
void after_(int wx, int wy);
int get_dir(char c);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T = 1;
    while (true)
    {
        int wx, wy;

        cin >> R >> C;

        if (R == 0 && C == 0) break;

        for (int i = 0; i < R; i++)
        {
            cin >> board[i];

            for (int j = 0; j < C; j++)
                if (board[i][j] == 'w' || board[i][j] == 'W')
                    wx = i, wy = j;
        }

        cin >> cmd;

        for (string::iterator i = cmd.begin(); i != cmd.end(); i++)
        {
            if (is_complete()) break;

            char a = (*i);
            int d = get_dir(a);

            int nx = wx + dx[d], ny = wy + dy[d];
            int nnx = nx + dx[d], nny = ny + dy[d];

            if (is_wall(nx, ny)) continue;
            if (is_box(nx, ny) && (is_box(nnx, nny) || is_wall(nnx, nny))) continue;

            if (is_box(nx, ny))
                push_(nx, ny, nnx, nny);
            else
                move_(nx, ny);
            
            after_(wx, wy);
            wx = nx, wy = ny;
        }

        cout << "Game " << T++ << ": ";

        if (is_complete())
            cout << "complete" << "\n";
        else
            cout << "incomplete" << "\n";

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
                cout << board[i][j];
            cout << "\n";
        }
    }

    return 0;
}

bool is_complete()
{
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (board[i][j] == 'b')
                return false;
    
    return true;
}

bool is_wall(int x, int y)
{
    return board[x][y] == '#';
}

bool is_box(int x, int y)
{
    return board[x][y] == 'b' || board[x][y] == 'B';
}

void move_(int nx, int ny)
{
    if (board[nx][ny] == '.') board[nx][ny] = 'w';
    else if (board[nx][ny] == '+') board[nx][ny] = 'W';
}

void push_(int nx, int ny, int nnx, int nny)
{
    if (board[nnx][nny] == '.') board[nnx][nny] = 'b';
    else if (board[nnx][nny] == '+') board[nnx][nny] = 'B';

    board[nx][ny] = (board[nx][ny] == 'B') ? 'W' : 'w';
}

void after_(int wx, int wy)
{
    if (board[wx][wy] == 'w') board[wx][wy] = '.';
    else if (board[wx][wy] == 'W') board[wx][wy] = '+';
}

int get_dir(char c)
{
    if (c == 'U') return 0;
    else if (c == 'D') return 1;
    else if (c == 'L')  return 2;
    else return 3;
}