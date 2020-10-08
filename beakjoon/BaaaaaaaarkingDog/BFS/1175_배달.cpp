#include <iostream>
#include <queue>

using namespace std;

const int MAX = 50;
const int dx[] = { -1, 1, 0, 0 }; 
const int dy[] = { 0, 0, -1, 1 };

struct person
{
    int x, y, prev_d;
    bool c, k;
};

int N, M;
char board[MAX][MAX];
int dist[MAX][MAX][4][2][2];

int get_distance(int sx, int sy);
person make_person(int x, int y, int prev_d, bool c, bool k);

int main(int argc, char const *argv[])
{
    int sx, sy;
    bool flag = false;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string row; cin >> row;

        for (int j = 0; j < M; j++)
        {
            board[i][j] = row[j];

            if (board[i][j] == 'S')
                sx = i, sy = j;
            else if (board[i][j] == 'C')
            {
                if (flag) board[i][j] = 'K';
                else flag = true;
            }
        }
    }

    cout << get_distance(sx, sy) << "\n";

    return 0;
}

int get_distance(int sx, int sy)
{
    fill_n(&dist[0][0][0][0][0], MAX * MAX * 4 * 2 * 2, -1);
    queue<person> q;

    for (int i = 0; i < 4; i++)
    {
        dist[sx][sy][i][0][0] = 0;
        q.push(make_person(sx, sy, i, 0, 0));
    }

    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y, prev_d = q.front().prev_d;
        bool c = q.front().c, k = q.front().k;
        q.pop();

        if (c && k)
            return dist[x][y][prev_d][c][k];
        
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            bool nc = c, nk = k;

            if (nx < 0 || nx >= N || ny < 0 || ny >= M || board[nx][ny] == '#')
                continue;

            if (board[nx][ny] == 'C') nc = true;
            if (board[nx][ny] == 'K') nk = true;
            
            if (dist[nx][ny][i][nc][nk] != -1 || prev_d == i)
                continue;
           
            dist[nx][ny][i][nc][nk] = dist[x][y][prev_d][c][k] + 1;
            q.push(make_person(nx, ny, i, nc, nk));
        }
    }

    return -1;
}

person make_person(int x, int y, int prev_d, bool c, bool k)
{
    person p = { x, y, prev_d, c, k };
    return p;
}
