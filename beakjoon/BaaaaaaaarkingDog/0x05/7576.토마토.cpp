#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1000;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N, M;
int tomato[MAX][MAX];
queue< pair<int, int> > q;

int bfs()
{

    while(!q.empty())
    {
        pair<int, int> c = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx, ny;
            nx = c.first + dx[i];
            ny = c.second + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;

            if (tomato[nx][ny] == 0)
            {
                tomato[nx][ny] = tomato[c.first][c.second] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }

    int depth = 0;
    bool possible = true;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (tomato[i][j] == 0)
            {
                possible = false;
                break;
            }
            else if (tomato[i][j] > depth)
                depth = tomato[i][j];
        }

        if (possible == false)
            break;
    }

    if (possible)
        return depth - 1;
    else
        return -1;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> M >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> tomato[i][j];

            if (tomato[i][j] == 1)
                q.push(make_pair(i, j));
        }
    }

    int answer = bfs();
    cout << answer << "\n";

    return 0;
}
