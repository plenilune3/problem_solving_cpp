#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N, M;
int board[MAX][MAX];
queue< pair<int, int> > q1, q2;
bool visited[MAX][MAX];

void melting_cheese()
{
    while (!q1.empty())
    {
        int x = q1.front().first, y = q1.front().second;
        q1.pop();

        board[x][y] = 0;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            
            if (visited[nx][ny])
                continue;
            
            visited[nx][ny] = true;
            
            if (board[nx][ny] == 0)
                q1.push(make_pair(nx, ny));
            else
                q2.push(make_pair(nx, ny));
        }
    }
}

int main(int argc, char const *argv[])
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            if (i == 0 || j == 0 || i == N - 1 || j == M - 1)
            {
                visited[i][j] = true;
                q1.push(make_pair(i, j));
            }

            cin >> board[i][j];
        }

    
    int time = 0;
    int count_cheese = 0;

    while (true)
    {
        melting_cheese();

        if (q2.empty())
            break;

        count_cheese = q2.size();

        q1 = q2;
        q2 = queue< pair<int, int> > ();

        time += 1;
    }

    cout << time << "\n";
    cout << count_cheese << "\n";

    return 0;
}
