#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAX_N = 50;
const int MAX_M = 50;
const int MAX_G = 5;
const int MAX_R = 5;

int N, M, G, R, answer = INT_MIN;
int garden[MAX_N][MAX_M];
bool selected[MAX_G + MAX_R];
vector< pair<int, int> > t;
vector< pair<int, int> > g;
vector< pair<int, int> > r;

int bfs(vector< pair<int, int> >& g, vector< pair<int, int> >& r)
{
    const int dx[] = { -1, 1, 0, 0 };
    const int dy[] = { 0, 0, -1, 1 };
    int flower_cnt = 0;
    queue< pair<int, int> > q;
    pair<int, int> visited[MAX_N][MAX_M];
    fill_n(&visited[0][0], MAX_N * MAX_M, make_pair(-1, 0));

    for (vector< pair<int, int> >::iterator iter = g.begin(); iter != g.end(); iter++)
    {
        visited[(*iter).first][(*iter).second].first = 0;
        visited[(*iter).first][(*iter).second].second = 2;
        q.push((*iter));
    }
    
    for (vector< pair<int, int> >::iterator iter = r.begin(); iter != r.end(); iter++)
    {
        visited[(*iter).first][(*iter).second].first = 0;
        visited[(*iter).first][(*iter).second].second = 1;
        q.push((*iter));
    }

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();

        if (visited[x][y].second == 3)
            continue;

        for (int i = 0; i < 4 ; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M || garden[nx][ny] == 0)
                continue;
            
            if (visited[nx][ny].second == 1)
            {
                if (visited[x][y].second == 2 && (visited[nx][ny].first == visited[x][y].first + 1))
                {
                    visited[nx][ny].first = visited[x][y].first + 1;
                    visited[nx][ny].second = 3;
                    flower_cnt += 1;
                }
            }
            
            else if (visited[nx][ny].second == 2)
            {
                if (visited[x][y].second == 1 && (visited[nx][ny].first == visited[x][y].first + 1))
                {
                    visited[nx][ny].first = visited[x][y].first + 1;
                    visited[nx][ny].second = 3;
                    flower_cnt += 1;
                }
            }
            
            else if (visited[nx][ny].second == 0 && visited[nx][ny].first == -1)
            {
                visited[nx][ny].first = visited[x][y].first + 1;
                visited[nx][ny].second = visited[x][y].second;
                q.push(make_pair(nx, ny));
            }
        }    
    }
    
    return flower_cnt;
}

void dfs(int depth, int length, int red, int green)
{
    if (red ==  0 && green == 0)
    {
        answer = max(answer, bfs(g, r));
        return;
    }

    if (depth == length)
        return;
    
    for (int i = depth; i < t.size(); i++)
    {
        if (red > 0)
        {
            r.push_back(t[i]);
            dfs(i + 1, length, red - 1, green);
            r.pop_back();
        }
        if (green > 0)
        {
            g.push_back(t[i]);
            dfs(i + 1, length, red, green - 1);
            g.pop_back();
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> G >> R;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> garden[i][j];

            if (garden[i][j] == 2)
                t.push_back(make_pair(i, j));
        }
    
    dfs(0, t.size(), R, G);
    cout << answer << "\n";

    return 0;
}
