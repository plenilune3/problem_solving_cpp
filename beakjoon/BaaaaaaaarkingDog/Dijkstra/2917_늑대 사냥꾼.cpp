#include <iostream>
#include <queue>
#include <climits>
#include <vector>

using namespace std;

const int MAX = 501;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

struct wolf
{
    int x, y, d, c;

    bool operator<(const wolf &w) const
    {
        if (d != w.d) return d < w.d;
        else if (c != w.c) return c < w.c;
        else if (x != w.x) return x < w.x;
        else return y < w.y;
    }
};

int N, M;
char board[MAX][MAX];
int dist[MAX][MAX];
queue< pair<int, int> > q;
int sx, sy, tx, ty;

int abs(int a, int b);
wolf make_wolf(int x, int y, int d, int c);
void find_distance();
int find_path(wolf w);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    fill_n(&dist[0][0], MAX * MAX, -1);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 'V')
                sx = i, sy = j;
            else if (board[i][j] == 'J')
                tx = i, ty = j;
            else if (board[i][j] == '+')
            {
                q.push(make_pair(i, j));
                dist[i][j] = 0;
            }
        }
    
    find_distance();

    int answer = find_path(make_wolf(sx, sy, dist[sx][sy], dist[sx][sy]));
    cout << answer << "\n";
   
    return 0;
}

wolf make_wolf(int x, int y, int d, int c)
{
    wolf w = { x, y, d, c };
    return w;
}

void find_distance()
{
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            
            if (dist[nx][ny] != -1)
                continue;
            
            dist[nx][ny] = dist[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
}

int find_path(wolf w)
{
    int visited[MAX][MAX];
    fill_n(&visited[0][0], MAX * MAX, INT_MIN);
    priority_queue<wolf> pq;
    visited[w.x][w.y] = w.d;
    pq.push(w);

    while (!pq.empty())
    {
        int x = pq.top().x, y = pq.top().y, d = pq.top().d, c = pq.top().c;
        pq.pop();

        if (visited[x][y] > d)
            continue;
        
        if (x == tx && y == ty)
            return c;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            
            int nd = dist[nx][ny];

            if (visited[nx][ny] < nd)
            {
                visited[nx][ny] = nd;
                pq.push(make_wolf(nx, ny, nd, min(c, nd)));
            }
        }
    }

    return -1;
}