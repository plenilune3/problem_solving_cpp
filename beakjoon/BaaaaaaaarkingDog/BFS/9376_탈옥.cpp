#include <iostream>
#include <deque>
#include <vector>

using namespace std;

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };
const int MAX = 102;

int height, width;
char prison[MAX][MAX];
int dist[MAX][MAX][3];

void bfs(int x, int y, int who)
{
    deque< pair<int, int> > q;
    dist[x][y][who] = 0;
    q.push_back(make_pair(x, y));

    while (!q.empty())
    {
        int cx = q.front().first, cy = q.front().second; q.pop_front();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i], ny = cy + dy[i];

            if (nx < 0 || nx > height + 1 || ny < 0 || ny > width + 1)
                continue;
            
            if (dist[nx][ny][who] >= 0 || prison[nx][ny] == '*')
                continue;
            
            if (prison[nx][ny] == '#')
            {
                dist[nx][ny][who] = dist[cx][cy][who] + 1;
                q.push_back(make_pair(nx, ny));
            }
            else if (prison[nx][ny] == '.')
            {
                dist[nx][ny][who] = dist[cx][cy][who];
                q.push_front(make_pair(nx, ny));
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
        fill_n(&prison[0][0], MAX * MAX, '.');
        fill_n(&dist[0][0][0], MAX * MAX * 3, -1);

        vector< pair<int, int> > v;
        v.push_back(make_pair(0, 0));

        cin >> height >> width;

        for (int i = 1; i <= height; i++)
            for (int j = 1; j <= width; j++)
            {
                cin >> prison[i][j];

                if (prison[i][j] == '$')
                {
                    prison[i][j] = '.';
                    v.push_back(make_pair(i, j));
                }
            }
        
        for (int i = 0; i < 3; i++)
            bfs(v[i].first, v[i].second, i);
        
        int answer = MAX * MAX;

        for (int i = 0; i < height + 2; i++)
            for (int j = 0; j < width + 2; j++)
                if (prison[i][j] != '*')
                {
                    int k = dist[i][j][0] + dist[i][j][1] + dist[i][j][2];

                    if (prison[i][j] == '#')
                        k -= 2;
                    
                    if (k < 0) continue;

                    answer = min(k, answer);
                }
        
        cout << answer << "\n";
    }

    return 0;
}
