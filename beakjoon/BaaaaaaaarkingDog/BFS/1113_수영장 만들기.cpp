#include <iostream>
#include <queue>

using namespace std;

const int MAX = 52;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N, M, answer, max_height;
int board[MAX][MAX];
bool visited[MAX][MAX];

void flood_fill(int x, int y, int height);
int count_(int height);
bool is_out_of_range(int x, int y);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        string input; cin >> input;

        for (int j = 1; j <= M; j++)
            max_height = max(max_height, board[i][j] = input[j - 1] - '0');
    }

    for (int h = 1; h <= max_height; h++)
    {
        fill_n(&visited[0][0], MAX * MAX, false);
        flood_fill(0, 0, h);
        answer += count_(h);
    }

    cout << answer << "\n";

    return 0;
}

void flood_fill(int x, int y, int height)
{
    queue< pair<int, int> > q;
    visited[x][y] = true;
    board[x][y] = height;
    q.push(make_pair(x, y));

    while (!q.empty())
    {
        int cx = q.front().first, cy = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int nx = cx + dx[d], ny = cy + dy[d];

            if (is_out_of_range(nx, ny) || visited[nx][ny]) continue;

            if (board[nx][ny] >= height) continue;

            visited[nx][ny] = true;
            board[nx][ny] = height;
            q.push(make_pair(nx, ny));
        }
    }
}

int count_(int height)
{
    int result = 0;

    for (int i = 0; i < N + 2; i++)
        for (int j = 0; j < M + 2; j++)
            if (board[i][j] < height)
            {
                result += height - board[i][j];
                board[i][j] = height;
            }
    
    return result;
}

bool is_out_of_range(int x, int y)
{
    return x < 0 || x >= N + 2 || y < 0 || y >= M + 2;
}
