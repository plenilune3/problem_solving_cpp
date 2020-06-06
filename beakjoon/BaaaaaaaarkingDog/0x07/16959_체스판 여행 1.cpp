#include <iostream>
#include <queue>
#include <climits>

using namespace std;

const int MAX = 10;
const int knight_dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
const int knight_dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
const int rook_dx[] = { -1, 1, 0, 0 };
const int rook_dy[] = { 0, 0, -1, 1 };
const int bishop_dx[] = { -1, 1, 1, -1 };
const int bishop_dy[] = { 1, 1, -1, -1 };

struct piece
{
    int x, y, num, type;
};

int N, answer = INT_MAX;
int board[MAX][MAX];
int dist[MAX][MAX][MAX * MAX + 1][3];

int bfs()
{
    fill_n(&dist[0][0][0][0], MAX * MAX * (MAX * MAX + 1) * 3, -1);
    queue< piece > q;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (board[i][j] == 1)
                for (int k = 0; k < 3; k++)
                {
                    piece p = { i, j, 1, k };
                    dist[i][j][1][k] = 0;
                    q.push(p);
                }
    
    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y;
        int num = q.front().num, type = q.front().type;
        q.pop();

        if (num == N * N)
            return dist[x][y][num][type];

        for (int i = 0; i < 3; i++)
        {
            if (i == type) continue;

            if (dist[x][y][num][i] == -1)
            {
                dist[x][y][num][i] = dist[x][y][num][type] + 1;
                piece p = { x, y, num, i };
                q.push(p);
            }
        }

        if (type == 0)
        {
            for (int i = 0; i < 8; i++)
            {
                int nx = x + knight_dx[i], ny = y + knight_dy[i];

                if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                    continue;
                
                int num_next = board[nx][ny] == num + 1 ? num + 1 : num;
                
                if (dist[nx][ny][num_next][type] == -1)
                {
                    dist[nx][ny][num_next][type] = dist[x][y][num][type] + 1;
                    piece p = { nx, ny, num_next, type };
                    q.push(p);
                }
            }
        }
        else if (type == 1)
        {
            for (int i = 0; i < 4; i++)
            {
                for (int k = 1; k <= N; k++)
                {
                    int nx = x + rook_dx[i] * k, ny = y + rook_dy[i] * k;

                    if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                        break;
                    
                    int num_next = board[nx][ny] == num + 1 ? num + 1 : num;

                    if (dist[nx][ny][num_next][type] == -1)
                    {
                        dist[nx][ny][num_next][type] = dist[x][y][num][type] + 1;
                        piece p = { nx, ny, num_next, type };
                        q.push(p);
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                for (int k = 1; k <= N; k++)
                {
                    int nx = x + bishop_dx[i] * k, ny = y + bishop_dy[i] * k;

                    if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                        break;
                    
                    int num_next = board[nx][ny] == num + 1 ? num + 1 : num;

                    if (dist[nx][ny][num_next][type] == -1)
                    {
                        dist[nx][ny][num_next][type] = dist[x][y][num][type] + 1;
                        piece p = { nx, ny, num_next, type };
                        q.push(p);
                    }
                }
            }
        }
    }

    return -1;
}


int main(int argc, char const *argv[])
{
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
        
    cout << bfs() << "\n";

    return 0;
}
