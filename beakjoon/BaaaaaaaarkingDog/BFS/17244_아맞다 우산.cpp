#include <iostream>
#include <queue>

using namespace std;

const int MAX = 51;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

struct P
{
    int x, y, k;

    P(int _x, int _y, int _k) : x(_x), y(_y), k(_k) {};
};


int N, M, K;
pair<int, int> S, E;
char A[MAX][MAX];
int visited[MAX][MAX][(1 << 5)];

int find_path(pair<int, int> S, pair<int, int> E, int K);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    fill_n(&visited[0][0][0], MAX * MAX * (1 << 5), -1);
    cin >> M >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> A[i][j];

            if (A[i][j] == 'S')
            {
                S = make_pair(i, j);
                A[i][j] = '.';
            }
            if (A[i][j] == 'E')
            {
                E = make_pair(i, j);
                A[i][j] = '.';
            }
            if (A[i][j] == 'X')
                A[i][j] = '0' + K++;
        }
    
    int answer = find_path(S, E, K);

    cout << answer << "\n";

    return 0;
}

int find_path(pair<int, int> S, pair<int, int> E, int K)
{
    queue<P> q;
    visited[S.first][S.second][0] = 0;
    q.push(P(S.first, S.second, 0));

    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y, k = q.front().k;
        q.pop();

        if (x == E.first && y == E.second && k == ((1 << K) - 1))
            return visited[x][y][k];

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d], ny = y + dy[d], nk = k;

            if (nx < 0 || nx >= N || ny < 0 || ny >= M || A[nx][ny] == '#')
                continue;
           
            if (A[nx][ny] != '.')
                nk = nk | (1 << A[nx][ny] - '0');

            if (visited[nx][ny][nk] != -1)
                continue;

            visited[nx][ny][nk] = visited[x][y][k] + 1;
            q.push(P(nx, ny, nk));
        }
    }

    return -1;
}