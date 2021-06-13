#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1e3 + 1;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

struct person
{
    int x, y, t, k;

    person() : x(0), y(0), t(0), k(0) {}
    person(int _x, int _y, int _t, int _k) : x(_x), y(_y), t(_t), k(_k) {}
};

int N, M, K;
char board[MAX][MAX];
int dist[MAX][MAX][2][11];

int calculate_dist(int sx, int sy, int tx, int ty);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    
    int answer = calculate_dist(0, 0, N - 1, M - 1);

    if (answer != -1)
        cout << answer + 1 << "\n";
    else
        cout << -1 << "\n";

	return 0;
}

int calculate_dist(int sx, int sy, int tx, int ty)
{
    fill_n(&dist[0][0][0][0], MAX * MAX * 2 * 11, -1);
    queue<person> q;
    dist[sx][sy][0][0] = 0;
    q.push(person(0, 0, 0, 0));

    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y, t = q.front().t, k = q.front().k;
        q.pop();

        if (x == tx && y == ty)
            return dist[x][y][t][k];

        if (dist[x][y][1 - t][k] == -1)
        {
            dist[x][y][1 - t][k] = dist[x][y][t][k] + 1;
            q.push(person(x, y, 1 - t, k));
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            int nt = 1 - t, nk = k;

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (board[nx][ny] == '1')
                nk += 1;
            if ((t == 1 && board[nx][ny] == '1') || nk > K)
                continue;
            if (dist[nx][ny][nt][nk] != -1)
                continue;
            
            dist[nx][ny][nt][nk] = dist[x][y][t][k] + 1;
            q.push(person(nx, ny, nt, nk));
        }
    }

    return -1;
}
