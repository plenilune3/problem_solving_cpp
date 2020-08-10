#include <iostream>

using namespace std;

const int MAX = 50;
const int dx[] = { 0, -1, 0, 1 };
const int dy[] = { -1, 0, 1, 0 };

int N, M, result;
int castle[MAX][MAX];
bool visited[MAX][MAX];

int dfs(int x, int y)
{
    int ret = 1;
    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 0 || nx >= M || ny < 0 || ny >= N || visited[nx][ny])
            continue;
        
        if ((castle[x][y] & (1 << i)) == false)
            ret += dfs(nx, ny);
    }

    return ret;
}

pair<int, int> get_max()
{
    fill_n(&visited[0][0], MAX * MAX, false);
    int cnt = 0, area_max = 0;

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (visited[i][j] == false)
            {
                cnt += 1;
                area_max = max(area_max, dfs(i, j));
            }
    
    return make_pair(cnt, area_max);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> castle[i][j];
    
    pair<int, int> answer = get_max();

    cout << answer.first << "\n" << answer.second << "\n";

    for (int x = 0; x < M; x++)
        for (int y = 0; y < N; y++)
        {
            for (int k = 1; k <= 8; k <<= 1)
                if (castle[x][y] & k)
                {
                    castle[x][y] -= k;
                    pair<int, int> c = get_max();
                    result = max(result, c.second);
                    castle[x][y] += k;
                }
        }

    cout << result << "\n";
}


