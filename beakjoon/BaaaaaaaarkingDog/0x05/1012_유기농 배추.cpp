#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 50;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int farm[MAX][MAX] = { 0 };
bool visited[MAX][MAX] = { false };

void dfs(int N, int M, int x, int y)
{
    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < M)
        {
            if (farm[nx][ny] == 1 && visited[nx][ny] == false)
            {
                dfs(N, M, nx, ny);
            }
        }
    }

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
        int answer = 0;
        int N, M, K;
        cin >> M >> N >> K;

        fill(&farm[0][0], &farm[MAX-1][MAX], 0);
        fill(&visited[0][0], &visited[MAX-1][MAX], false);

        // for (int i = 0; i < MAX; i++)
        // {
        //     for (int j = 0; j < MAX; j++)
        //     {
        //        farm[i][j] = 0;
        //        visited[i][j] = false; 
        //     }
        // }

        for (int k = 0; k < K; k++)
        {
            int x, y;
            cin >> x >> y;
            farm[y][x] = 1;
        }

        // for (int i = 0; i < N; i++)
        // {
        //     for (int j = 0; j < M; j++)
        //     {
        //         cout << farm[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (farm[i][j] == 1 && visited[i][j] == false)
                {
                    answer++;
                    dfs(N, M, i, j);
                }
            }
        }

        cout << answer << "\n";
    }

    return 0;
}
