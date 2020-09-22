#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 300;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int iceberg[MAX][MAX];
bool visited[MAX][MAX];
int N, M;

void dfs(int x, int y);
void melt();
int count_ice(int x, int y, int iceberg_copy[MAX][MAX]);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> iceberg[i][j];

    bool possible = true;
    int answer = 0;
    
    while (true)
    {
        fill_n(&visited[0][0], MAX * MAX, false);
        
        int cnt = 0;

        for (int i = 1; i < N - 1; i++)
            for (int j = 1; j < M - 1; j++)
                if (visited[i][j] == false && iceberg[i][j])
                {
                    dfs(i, j);
                    cnt += 1;
                }

        if (cnt >= 2 || cnt == 0)
        {
            possible = cnt >= 2 ? true : false;
            break;
        }

        melt();
        answer += 1;
    }

    if (possible)
        cout << answer << "\n";
    else
        cout << 0 << "\n";

    return 0;
}

void dfs(int x, int y)
{
    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 1 || nx >= N - 1 || ny < 1 || ny >= M - 1)
            continue;
        
        if (visited[nx][ny] == false && iceberg[nx][ny])
            dfs(nx, ny);
    }
}

void melt()
{
    int iceberg_copy[MAX][MAX];
    copy(&iceberg[0][0], &iceberg[0][0] + MAX * MAX, &iceberg_copy[0][0]);

    for (int x = 1; x < N - 1; x++)
        for (int y = 1; y < M - 1; y++)
        {
            if (iceberg_copy[x][y])
            {
                int cnt = count_ice(x, y, iceberg_copy);
                iceberg[x][y] = max(iceberg_copy[x][y] - cnt, 0);
            }
        }
}

int count_ice(int x, int y, int iceberg_copy[MAX][MAX])
{
    int cnt = 0;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];

        if (iceberg_copy[nx][ny] == 0)
            cnt += 1;
    }

    return cnt;
}