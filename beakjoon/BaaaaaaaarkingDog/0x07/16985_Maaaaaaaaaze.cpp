#include <iostream>
#include <queue>
#include <climits>

using namespace std;

struct coordinate
{
    int z, x, y;
};

const int MAX = 5;
const int dz[] = {-1, 1, 0, 0, 0, 0};
const int dx[] = {0, 0, -1, 1, 0, 0};
const int dy[] = {0, 0, 0, 0, -1, 1};

bool maze[MAX][MAX][MAX];
bool maze_new[MAX][MAX][MAX];
bool visited[MAX];
int dist[MAX][MAX][MAX];
int answer = INT_MAX;
vector<int> v;

void rotate(bool A[MAX][MAX])
{
    bool B[MAX][MAX];

    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            B[i][j] = A[MAX-1-j][i];
    
    copy(&B[0][0], &B[0][0] + MAX * MAX, &A[0][0]);
}

int bfs(coordinate s, coordinate t)
{
    fill_n(&dist[0][0][0], MAX*MAX*MAX, -1);

    queue<coordinate> q;
    dist[s.z][s.x][s.y] = 0;
    q.push(s);

    while(!q.empty())
    {
        coordinate c = q.front();
        q.pop();

        if (c.z == t.z && c.x == t.x && c.y == t.y)
            return dist[c.z][c.x][c.y];

        for (int i = 0; i < 6; i++)
        {
            int nz = c.z + dz[i];
            int nx = c.x + dx[i];
            int ny = c.y + dy[i];

            if (nz < 0 || nz >= MAX || nx < 0 || nx >= MAX || ny < 0 || ny >= MAX || dist[nz][nx][ny] != -1)
                continue;
            
            if (maze_new[nz][nx][ny] == true)
            {
                dist[nz][nx][ny] = dist[c.z][c.x][c.y] + 1;
                coordinate nc = { nz, nx, ny };
                q.push(nc);
            }
        }
    }

    return -1;
}

void dfs(int depth)
{
    if (depth == MAX)
    {
        if (maze_new[0][0][0] && maze_new[4][4][4])
        {
            coordinate s = {0, 0, 0};
            coordinate t = {4, 4, 4};
            int distance = bfs(s, t);

            if (distance != -1)
                answer = min(answer, distance);
        }

        return;
    }

    for (int i = 0; i < 4; i++)
    {
        rotate(maze_new[depth]);
        dfs(depth + 1);
    }
}

void permutations(int depth)
{
    if (depth == 5)
    {
        for (int i = 0; i < 5; i++)
            copy(&maze[v[i]][0][0], &maze[v[i]][0][0] + MAX * MAX, &maze_new[i][0][0]);
 
        dfs(0);
        return;
    }

    for (int i = 0; i < MAX; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            v.push_back(i);
            permutations(depth + 1);
            visited[i] = false;
            v.pop_back();
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for (int z = 0; z < MAX; z++)
        for (int x = 0; x < MAX; x++)
            for (int y = 0; y < MAX; y++)
                cin >> maze[z][x][y];

    permutations(0);

    if (answer == INT_MAX)
        cout << -1 << "\n";
    else
        cout << answer << "\n";

    return 0;
}
