#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAX = 1e2 + 1;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

struct cow
{
    int x, y, w, d;

    bool operator< (const cow &c) const
    {
        if (w != c.w) return w > c.w;
        else if (d != c.d) return d > c.d;
        else if (x != c.x) return x > c.x;
        else return y > c.y;
    }
};

int N, T;
int board[MAX][MAX];

cow make_cow(int x, int y, int w, int d);
int find_path(int x, int y);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> T;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    
    int answer = find_path(0, 0);

    cout << answer << "\n";
    
    return 0;
}

cow make_cow(int x, int y, int w, int d)
{
    cow c = { x, y, w, d };
    return c;
}

int find_path(int x, int y)
{
    int dist[N][N][3];
    fill_n(&dist[0][0][0], N * N * 3, INT_MAX);
    priority_queue<cow> pq;
    dist[x][y][0] = 0;
    pq.push(make_cow(x, y, 0, 0));

    while (!pq.empty())
    {
        int x = pq.top().x, y = pq.top().y, w = pq.top().w, d = pq.top().d;
        pq.pop();

        if (dist[x][y][d] < w)
            continue;
        
        if (x == N - 1 && y == N - 1)
            return dist[x][y][d];
        
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            
            int nw = board[nx][ny], nd = (d + 1) % 3; 
            int c = nd == 0 ? w + T + nw : w + T;

            if (dist[nx][ny][nd] > c)
            {
                dist[nx][ny][nd] = c;
                pq.push(make_cow(nx, ny, c, nd));
            }
        }
    }

    return -1;
}
