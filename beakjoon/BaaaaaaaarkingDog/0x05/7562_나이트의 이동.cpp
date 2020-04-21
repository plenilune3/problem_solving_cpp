#include <iostream>
#include <queue>

using namespace std;

const int MAX = 300;
int board[MAX][MAX];
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int N;

int bfs(pair<int, int> t, pair<int, int> s)
{
    queue< pair<int, int> > q;
    q.push(s);

    while (!q.empty())
    {
        pair<int, int> c = q.front();
        q.pop();
        
        if (t.first == c.first && t.second == c.second)
            break;

        for (int i = 0; i < 8; i++)
        {
            int nx = c.first + dx[i];
            int ny = c.second + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            
            if (board[nx][ny] == 0)
            {
                board[nx][ny] = board[c.first][c.second] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }

    return board[t.first][t.second] - 1;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        fill_n(&board[0][0], MAX*MAX, 0);

        cin >> N;
        pair<int, int> start;
        cin >> start.first >> start.second;
        pair<int, int> target;
        cin >> target.first >> target.second;

        board[start.first][start.second] = 1;

        int answer = bfs(target, start);
        cout << answer << "\n";

    }

    return 0;
}
