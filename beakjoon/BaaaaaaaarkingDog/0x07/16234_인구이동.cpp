#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 51;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int A[MAX][MAX];
bool visited[MAX][MAX];
int N, L, R, cnt;

int dfs(int depth, int x, int y, vector< pair<int, int> >& v)
{
    int result = A[x][y];
    visited[x][y] = true;
    v.push_back(make_pair(x, y));

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny])
            continue;
        
        int diff = abs(A[x][y] - A[nx][ny]);
        
        if (diff >= L && diff <= R)
        {
            cnt++;
            result += dfs(depth + 1, nx, ny, v);
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int answer = 0;
    cin >> N >> L >> R;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];
    
    while(true)
    {
        fill_n(&visited[0][0], MAX*MAX, false);
        bool possible = false;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                vector< pair<int, int> > v;
                int population = 0;

                if (visited[i][j] == false)
                {
                    cnt = 1;
                    population = dfs(0, i, j, v);
                }

                if (cnt > 1)
                {
                    possible = true;
                    int population_average = population / cnt;

                    vector< pair<int, int> >::iterator iter;
                    for (iter = v.begin(); iter != v.end(); iter++)
                        A[(*iter).first][(*iter).second] = population_average;
                }
            }
        
        if (possible == false)
            break;
        else
            answer++;
    }

    cout << answer << "\n";
    
    return 0;
}
