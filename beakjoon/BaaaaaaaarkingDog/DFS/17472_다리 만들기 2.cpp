#include <iostream>
#include <climits>
#include <vector>

using namespace std;

const int MAX = 10;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N, M, island_num = 1;
int answer = INT_MAX;
vector< pair<int, int> > v;
int island[MAX][MAX];
int bridge[MAX][MAX];
bool visited[MAX][MAX];
bool selected[7];
int adjacency[7][7];

int island_dfs(int depth, int x, int y, int island_num)
{
    int ret = 1;
    visited[x][y] = true;
    island[x][y] = island_num;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M || visited[nx][ny])
            continue;
        
        if (island[nx][ny])
            ret += island_dfs(depth + 1, nx, ny, island_num);
    }

    return ret;
}

int adjacency_dfs(int depth, int x)
{
    int ret = 1;
    selected[x] = true;

    for (int i = 1; i < island_num; i++)
        if (selected[i] == false && adjacency[x][i])
            ret += adjacency_dfs(depth + 1, i);
    
    return ret;
}

bool is_possible(int x, int y, int d)
{
    bool possible = false;

    int nx = x + dx[d];
    int ny = y + dy[d];
    int cnt = 0;

    while (true)
    {
        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            break;

        if (island[nx][ny])
        {
            if (cnt >= 2)
                possible = true;
            break;
        }
        
        cnt += 1;
        nx += dx[d];
        ny += dy[d];
    }

    return possible;
}

void install_bridge(int x, int y, int d)
{
    int nx = x + dx[d];
    int ny = y + dy[d];

    while (island[nx][ny] == 0)
    {
        bridge[nx][ny] += 1;

        nx += dx[d];
        ny += dy[d];
    }

    int a = island[x][y];
    int b= island[nx][ny];
    adjacency[a][b] += 1;
    adjacency[b][a] += 1;
}

void uninstall_bridge(int x, int y, int d)
{
    int nx = x + dx[d];
    int ny = y + dy[d];

    while (island[nx][ny] == 0)
    {
        bridge[nx][ny] -= 1;

        nx += dx[d];
        ny += dy[d];
    }

    int a = island[x][y];
    int b= island[nx][ny];
    adjacency[a][b] -= 1;
    adjacency[b][a] -= 1;
}


void backtracking(int depth, vector< pair<int, int> >::iterator i)
{
    if (depth == island_num - 2)
    {
        fill_n(&selected[0], 7, false);

        if (adjacency_dfs(0, 1) == island_num - 1)
        {
            int bridge_cnt = 0;
            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++)
                        bridge_cnt += bridge[i][j];
            
            answer = min(answer, bridge_cnt);
        }
        return;
    }

    vector< pair<int, int> >::iterator iter;
    for (iter = i; iter != v.end(); iter++)
    {
        int x = (*iter).first;
        int y = (*iter).second;

        for (int i = 0; i < 4; i++)
        {
            if (is_possible(x, y, i))
            {
                install_bridge(x, y, i);
                backtracking(depth + 1, iter);
                uninstall_bridge(x, y, i);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> island[i][j];

            if (island[i][j])
                v.push_back(make_pair(i, j));
        }
    
    for (int x = 0; x < N; x++)
        for (int y = 0; y < M; y++)
            if (island[x][y] && visited[x][y] == false)
                island_dfs(0, x, y, island_num++);

    backtracking(0, v.begin());

    if (answer == INT_MAX)
        cout << -1 << "\n";
    else
        cout << answer << "\n";

    return 0;
}
