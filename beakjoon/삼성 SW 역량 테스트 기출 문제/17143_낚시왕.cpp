#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct shark
{
    int x, y, s, d, z;
};

const int MAX = 101;
const int dx[5] = { 0, -1, 1, 0, 0 };
const int dy[5] = { 0, 0, 0, 1, -1 };
 
int R, C, M, answer;
shark board[MAX][MAX];

int fishing(int y);
void move_shark();
void move(shark &s, shark board[MAX][MAX]);
shark make_shark(int x, int y, int s, int d, int z);

int main(int argc, char const *argv[])
{
    cin >> R >> C >> M;

    for (int i = 0; i < M; i++)
    {
        int x, y, s, d, z;
        cin >> x >> y >> s >> d >> z;
        board[x - 1][y - 1] = make_shark(x - 1, y - 1, s, d, z);
    }

    for (int y = 0; y < C; y++)
    {
        int size = fishing(y);
        answer += size;

        move_shark();
    }

    cout << answer << "\n";

    return 0;
}    

shark make_shark(int x, int y, int s, int d, int z)
{    
    if (d == 1 || d == 2) s = s % (R * 2 - 2);
    else s = s % (C * 2 - 2);

    shark sh = { x, y, s, d, z };
    return sh;
}

int fishing(int y)
{
    for (int x = 0; x < R; x++)
        if (board[x][y].z)
        {
            int size = board[x][y].z;
            board[x][y] = make_shark(0 ,0, 0, 0, 0);
            return size;
        }

    return 0;
}

void move_shark()
{
    shark board_c[MAX][MAX];
    fill_n(&board_c[0][0], MAX * MAX, make_shark(0, 0, 0, 0, 0));

    for (int x = 0; x < R; x++)
        for (int y = 0; y < C; y++)
            if (board[x][y].z)
                move(board[x][y], board_c);
    
    copy(&board_c[0][0], &board_c[0][0] + MAX * MAX, &board[0][0]);
}

void move(shark &s, shark board[MAX][MAX])
{
    int nx = s.x, ny = s.y;

    for (int i = 0; i < s.s; i++)
    {
        nx = s.x + dx[s.d], ny = s.y + dy[s.d];

        if (nx < 0 || nx >= R || ny < 0 || ny >= C)
        {
            if (s.d == 1) s.d = 2;
            else if (s.d == 2) s.d = 1;
            else if (s.d == 3) s.d = 4;
            else s.d = 3;
        }

        nx = s.x + dx[s.d], ny = s.y + dy[s.d];
        s.x = nx, s.y = ny;
    }

    if (s.z >= board[nx][ny].z) board[nx][ny] = s;
}