#include <iostream>
#include <queue>
#include <string>

using namespace std;

const int dx[] = { -1, -1, -1, 0, 1, 1, 1, 0, 0};
const int dy[] = { -1, 0, 1, 1, 1, 0, -1, -1, 0};

struct state
{
    int x, y, time;
};

char board[8][8];
bool visited[8][8][9];

bool bfs()
{
    queue<state> q;
    visited[7][0][0] = true;
    state init = { 7, 0, 0 };
    q.push(init);

    while(!q.empty())
    {
        int x = q.front().x, y = q.front().y, time = q.front().time;
        q.pop();

        if (x == 0 && y == 7)
            return true;
        
        for (int i = 0; i < 9; i++)
        {
            int nx = x + dx[i], ny = y + dy[i], nt = min(time + 1, 8);

            if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8 || visited[nx][ny][nt])
                continue;
            
            if (nx - time >= 0 && board[nx - time][ny] == '#')
                continue;
            
            if (nx - time - 1 >= 0 && board[nx - time - 1][ny] == '#')
                continue;
            
            state n = { nx, ny, nt };
            visited[nx][ny][nt] = true;
            q.push(n);
        }
    }

    return false;
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 8; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < 8; j++)
            board[i][j] = s[j];
    }

    cout << bfs() << "\n";

    return 0;
}
