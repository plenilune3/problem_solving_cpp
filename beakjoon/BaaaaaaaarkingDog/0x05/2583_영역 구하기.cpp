#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 100;
bool grid[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
vector<int> v;
int M, N, K;
int cnt = 0, area;

void dfs(int x, int y)
{
    visited[x][y] = true;
    area++;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;
        
        if (visited[nx][ny] == false && grid[nx][ny] == false)
            dfs(nx, ny);
    }

}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> K;

    fill_n(&grid[0][0], MAX*MAX, 0);
    fill_n(&visited[0][0], MAX*MAX, false);

    for (int k = 0; k < K; k++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        for (int i = a; i < c; i++)
            for (int j = b; j < d; j++)
                grid[i][j] = true;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (visited[i][j] == false && grid[i][j] == false)
            {
                area = 0;
                dfs(i, j);
                cnt++;
                v.push_back(area);
            }
        }
    }

    sort(v.begin(), v.end());
    int length = v.size();

    cout << cnt << "\n";

    for (int i = 0; i < length; i++)
        cout << v[i] << " ";

    return 0;
}

