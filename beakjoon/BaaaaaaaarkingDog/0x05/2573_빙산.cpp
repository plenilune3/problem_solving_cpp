#include <iostream>

using namespace std;

const int MAX = 300;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int iceberg[MAX][MAX];
bool visited[MAX][MAX];
int N, M;

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
    int copy[MAX][MAX];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            copy[i][j] = iceberg[i][j];
    
    for (int x = 1; x < N - 1; x++)
        for (int y = 1; y < M - 1; y++)
        {
            if (copy[x][y])
            {
                int cnt = 0;

                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (copy[nx][ny] == 0)
                        cnt++;
                }

                iceberg[x][y] = max(copy[x][y] - cnt, 0);
            }
        }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int answer = 0;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> iceberg[i][j];

    bool possible = true;
    while (possible)
    {
        melt();
        answer++;

        fill_n(&visited[0][0], MAX*MAX, false);

        int cnt = 0;

        for (int i = 1; i < N - 1; i++)
            for (int j = 1; j < M - 1; j++)
                if (visited[i][j] == false && iceberg[i][j])
                {
                    cnt++;
                    dfs(i,j);
                }

        if (cnt > 1)
            break;
        else if (cnt == 0)
            possible = false;
    }

    if (possible)
        cout << answer << "\n";
    else
        cout << 0 << "\n";

    return 0;
}
