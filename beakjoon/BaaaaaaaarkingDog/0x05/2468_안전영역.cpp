#include <iostream>
#include <algorithm>

using namespace std;


const int MAX = 100;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int N;
int safety[MAX][MAX];
bool visited[MAX][MAX];


void dfs(int h, int x, int y)
{
    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue;
        
        if (visited[nx][ny] == false && safety[nx][ny] >= h)
            dfs(h, nx, ny);

    }

}

int main(int argc, char const *argv[])
{
    int height_max = -1;
    int height_min = 101;
    int count_max = 1;
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> safety[i][j];
            
            height_max = max(height_max, safety[i][j]);
            height_min = min(height_min, safety[i][j]);
        }
    
    for (int h = height_min; h <= height_max; h++)
    {
        fill_n(&visited[0][0], MAX*MAX, false);
        int count = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (visited[i][j] == false && safety[i][j] >= h)
                {
                    dfs(h, i, j);
                    count++;
                }
            }
        }

        count_max = max(count, count_max);
    }

    cout << count_max << "\n";

    return 0;
}
