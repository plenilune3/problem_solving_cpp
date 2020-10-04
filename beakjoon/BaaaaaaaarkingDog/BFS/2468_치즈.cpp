#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N, M;
bool board[MAX][MAX];
bool visited[MAX][MAX];
int counter[MAX][MAX];
queue< pair<int, int> > q1, q2;

bool is_out_of_range(int x, int y);
void find_cheese();

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];

            if (i == 0 || j == 0 || i == N - 1 || j == M - 1)
            {
                visited[i][j] = true;
                q1.push(make_pair(i, j));
            }
        }
    
    int cnt = 0;

    while (true)
    {
        if (q1.empty())
            break;
        
        find_cheese();

        q1 = q2, q2 = queue< pair<int, int> > ();

        cnt += 1;
    }

    cout << cnt - 1 << "\n";
    
    return 0;
}

bool is_out_of_range(int x, int y)
{
    return x < 0 || x >= N || y < 0 || y >= M;
}

void find_cheese()
{
    while (!q1.empty())
    {
        int x = q1.front().first, y = q1.front().second;
        q1.pop();

        board[x][y] = false;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (is_out_of_range(nx, ny) || visited[nx][ny])
                continue;
            
            if (board[nx][ny])
            {
                if (++counter[nx][ny] >= 2)
                {
                    visited[nx][ny] = true;
                    q2.push(make_pair(nx, ny));
                }
            }
            else
            {
                visited[nx][ny] = true;
                q1.push(make_pair(nx, ny));
            }
        }
    }
}




