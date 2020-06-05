#include <iostream>
#include <queue>

using namespace std;

const int MAX = 50;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int board[MAX][MAX];
int dist[MAX][MAX];
int N, M, R, C, L;

void bfs(int x, int y)
{
    queue< pair<int, int> > q;
    dist[x][y] = 1;
    q.push(make_pair(x, y));

    while(!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M || dist[nx][ny] != 0 || board[nx][ny] == 0)
                continue;
            
            if (i == 0)
            {
                if ((board[x][y] == 1 || board[x][y] == 2 || board[x][y] == 4 || board[x][y] == 7) && (board[nx][ny] == 1 || board[nx][ny] == 2 || board[nx][ny] == 5 || board[nx][ny] == 6))
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }

            else if (i == 1)
            {
                if ((board[x][y] == 1 || board[x][y] == 2 || board[x][y] == 5 || board[x][y] == 6) && (board[nx][ny] == 1 || board[nx][ny] == 2 || board[nx][ny] == 4 || board[nx][ny] == 7))
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }

            else if (i == 2)
            {
                if ((board[x][y] == 1 || board[x][y] == 3 || board[x][y] == 6 || board[x][y] == 7) && (board[nx][ny] == 1 || board[nx][ny] == 3 || board[nx][ny] == 4 || board[nx][ny] == 5))
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
            
            else
            {
                if ((board[x][y] == 1 || board[x][y] == 3 || board[x][y] == 4 || board[x][y] == 5) && (board[nx][ny] == 1 || board[nx][ny] == 3 || board[nx][ny] == 6 || board[nx][ny] == 7))
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        fill_n(&dist[0][0], MAX * MAX, 0);
        cin >> N >> M >> R >> C >> L;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> board[i][j];
        
        bfs(R, C);

        int answer = 0;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (dist[i][j] != 0 && dist[i][j] <= L)
                    answer += 1;

        cout << "#" << t << " " << answer << "\n";
    }

    return 0;
}
