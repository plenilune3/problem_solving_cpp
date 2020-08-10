#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 25;

int apart[MAX][MAX];
bool visited[MAX][MAX] = { false };
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1 ,1};
vector<int> v;
int N, area, cnt = 0;

void dfs(int x, int y)
{
    area++;
    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue;
        
        if (visited[nx][ny] == false && apart[nx][ny] == 1)
            dfs(nx, ny);
    }

}

int main(int argc, char const *argv[])
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%1d", &apart[i][j]);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j] == false && apart[i][j] == 1)
            {
                area = 0;
                dfs(i, j);
                v.push_back(area);
            }
        }
    }

    sort(v.begin(), v.end());
    
    int cnt = v.size();
    printf("%d\n", cnt);

    for (int i = 0; i < cnt; i++)
        printf("%d\n", v[i]);

    return 0;
}
