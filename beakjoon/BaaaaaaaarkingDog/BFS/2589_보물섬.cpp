#include <iostream>
#include <string>
#include <queue>

using namespace std;

const int MAX = 50;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N, M, answer = 0;
char board[MAX][MAX];
int dist[MAX][MAX];

void bfs(int x, int y)
{
    queue< pair<int, int> > q;
    fill_n(&dist[0][0], MAX * MAX, -1);

    dist[x][y] = 0;
    q.push(make_pair(x, y));

    while (!q.empty())
    {
        pair<int, int> c = q.front();
        q.pop();

        answer = max(answer, dist[c.first][c.second]);

        for (int i = 0; i < 4; i++)
        {
            int nx = c.first + dx[i], ny = c.second + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M || dist[nx][ny] != -1)
                continue;
            
            if (board[nx][ny] == 'L')
            {
                dist[nx][ny] = dist[c.first][c.second] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> board[i];
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (board[i][j] == 'L')
                bfs(i, j);
    
    cout << answer << "\n";

    return 0;
}
