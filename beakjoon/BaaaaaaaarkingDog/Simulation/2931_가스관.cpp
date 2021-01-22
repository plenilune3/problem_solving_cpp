#include <iostream>

using namespace std;

const int MAX = 26;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int R, C;
char board[MAX][MAX];

pair<int, int> find_empty(int x, int y);
void get_pipe(int &x, int &y, int &d);
int get_next_dir(int x, int y, int d);
char install_pipe(int x, int y);
bool is_out_of_range(int x, int y);
bool is_possible(int x, int y, int d);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int mx = 0, my = 0;

    cin >> R >> C;

    for (int i = 0; i < R; i++)
    {
        cin >> board[i];

        for (int j = 0; j < C; j++)
            if (board[i][j] == 'M')
                mx = i, my = j, board[i][j] = '.';
            else if (board[i][j] == 'Z')
                board[i][j] = '.';
    }

    pair<int, int> c = find_empty(mx, my);
    int x = c.first, y = c.second;
    char pipe = install_pipe(x, y);

    cout << x + 1 << " " << y + 1 << " " << pipe << "\n";

    return 0;
}

pair<int, int> find_empty(int x, int y)
{
    int d = 0;
    get_pipe(x, y, d);

    while (true)
    {
        if (board[x][y] == '.')
            break;
        
        d = get_next_dir(x, y, d);
        x += dx[d], y += dy[d];
    }

    return make_pair(x, y);
}

void get_pipe(int &x, int &y, int &d)
{
    for (int nd = 0; nd < 4; nd++)
    {
        int nx = x + dx[nd], ny = y + dy[nd];

        if (is_out_of_range(nx, ny)) continue;

        if (board[nx][ny] != '.')
        {
            x = nx, y = ny, d = nd;
            break;
        }
    }
}

int get_next_dir(int x, int y, int d)
{
    if (board[x][y] == '+' || board[x][y] == '|' || board[x][y] == '-')
        return d;
    
    else if (board[x][y] == '1')
        return (d == 0) ? 3 : 1;
    
    else if (board[x][y] == '2')
        return (d == 1) ? 3 : 0;
    
    else if (board[x][y] == '3')
        return (d == 1) ? 2 : 0;
    
    else
        return (d == 0) ? 2 : 1;
}

char install_pipe(int x, int y)
{
    bool p[4] = { false };

    for (int d = 0; d < 4; d++)
    {
        int nx = x + dx[d], ny = y + dy[d];

        if (is_out_of_range(nx, ny)) continue;

        if (is_possible(nx, ny, d))
            p[d] = true;
    }

    if (p[0] && p[1] && p[2] && p[3]) return '+';
    if (p[0] && p[1]) return '|';
    if (p[2] && p[3]) return '-';
    if (p[1] && p[3]) return '1';
    if (p[0] && p[3]) return '2';
    if (p[0] && p[2]) return '3';
    if (p[1] && p[2]) return '4';
}

bool is_up_or_down(int d)
{
    return d == 0 || d == 1;
}

bool is_possible(int x, int y, int d)
{
    if (d == 0)
        return !(board[x][y] == '.' || board[x][y] == '-' || board[x][y] == '2' || board[x][y] == '3');
    else if (d == 1)
        return !(board[x][y] == '.' || board[x][y] == '-' || board[x][y] == '1' || board[x][y] == '4');
    else if (d == 2)
        return !(board[x][y] == '.' || board[x][y] == '|' || board[x][y] == '3' || board[x][y] == '4');
    else
        return !(board[x][y] == '.' || board[x][y] == '|' || board[x][y] == '1' || board[x][y] == '2');
}

bool is_out_of_range(int x, int y)
{
    return x < 0 || x >= R || y < 0 || y >= C;
}