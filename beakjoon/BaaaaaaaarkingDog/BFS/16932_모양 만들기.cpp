#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int MAX = 1000;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N, M, answer;
int board[MAX][MAX];
int area[MAX][MAX];
bool visited[MAX][MAX];
vector<int> v;

int dfs(int x, int y, int z)
{
    int ret = 1;
    visited[x][y] = true;
    area[x][y] = z;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;
        
        if (board[nx][ny] == 1 && visited[nx][ny] == false)
            ret += dfs(nx, ny, z);
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int z = 1;
    v.push_back(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
        
    for (int x = 0; x < N; x++)
        for (int y = 0; y < M; y++)
            if (visited[x][y] == false && board[x][y] == 1)
            {
                v.push_back(dfs(x, y, z));
                z += 1;
            }
    
    for (int x = 0; x < N; x++)
        for (int y = 0; y < M; y++)
            if (board[x][y] == 0)
            {
                int result = 1;
                set<int> s;

                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i], ny = y + dy[i];

                    if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                        continue;
                    
                    s.insert(area[nx][ny]);
                }

                for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++)
                    result += v[(*iter)];
                
                answer = max(answer, result);
            }
    
    cout << answer << "\n";
    
    return 0;
}
