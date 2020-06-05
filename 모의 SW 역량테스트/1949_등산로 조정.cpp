#include <iostream>
#include <climits>
#include <vector>

using namespace std;

const int MAX = 8;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int board[MAX][MAX];
bool visited[MAX][MAX];
int N, K, answer;

void dfs(int depth, int x, int y, bool c)
{
    answer = max(answer, depth);

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny])
            continue;
        
        if (board[x][y] > board[nx][ny])
        {
            visited[nx][ny] = true;
            dfs(depth + 1, nx, ny, c);
            visited[nx][ny] = false;
        }

        if (c == false)
        {
            for (int k = 1; k <= K; k++)
            {
                board[nx][ny] -= k;
                if (board[x][y] > board[nx][ny])
                {
                    visited[nx][ny] = true;
                    dfs(depth + 1, nx, ny, true);
                    visited[nx][ny] = false;
                }
                board[nx][ny] += k;
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
        vector< pair<int, int> > v;
        int height_max = 0;
        answer = INT_MIN;
        
        cin >> N >> K;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                cin >> board[i][j];

                height_max = max(height_max, board[i][j]);
            }
        
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (board[i][j] == height_max)
                    v.push_back(make_pair(i, j));
        
        for (vector< pair<int, int> >::iterator iter = v.begin(); iter != v.end(); iter++)
        {
            fill_n(&visited[0][0], MAX * MAX, false);
            visited[(*iter).first][(*iter).second] = true;
            dfs(1, (*iter).first, (*iter).second, false);
        }

        cout << "#" << t << " " << answer << "\n";
    }

    return 0;
}
