#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 101;

struct bridge
{
    int x;
    int y;
    int bridge_length;
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int island[MAX][MAX];
bool visited[MAX][MAX]; 

int N;
int island_number = 1;

void dfs(int x, int y)
{
    visited[x][y] = true;
    island[x][y] = island_number;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx > N || ny < 0 || ny > N)
            continue;

        if (visited[nx][ny] == false && island[nx][ny] != 0)
            dfs(nx, ny);
    }
}

int bfs (bridge s, int s_num)
{
    queue< bridge > q;
    visited[s.x][s.y] = true;
    q.push(s);
    int length = MAX*MAX;

    while (!q.empty())
    {
        bridge c = q.front();
        q.pop();

        int x = c.x;
        int y = c.y;
        int bridge_length = c.bridge_length;

        if (island[x][y] != 0 && island[x][y] != s_num)
        {
            length = bridge_length;
            break;
        }
        
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx > N || ny < 0 || ny > N)
                continue;
            
            if (visited[nx][ny] == false && island[nx][ny] != s_num)
            {
                visited[nx][ny] = true;
                bridge nb = {nx, ny, bridge_length + 1};
                q.push(nb);
            }
        }
    }

    return length;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> island[i][j];
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (visited[i][j] == false && island[i][j] != 0)
            {
                dfs(i, j);
                island_number++;
            }

    int answer = MAX*MAX;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (island[i][j] != 0)
            {
                fill_n(&visited[0][0], MAX*MAX, false);
                bridge s = {i, j, 0};
                answer = min(answer, bfs(s, island[i][j]));
            }
        }
    }

    cout << answer - 1 << "\n";

    return 0;
}
