#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 10;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N, M, K, num, answer = 10000;
int board[MAX][MAX], bridge[MAX][MAX];
int adj[MAX][MAX];
bool visited[MAX][MAX], selected[MAX];
// vector< vector< pair<int, int> > > v(MAX);
vector< pair<int, int> > v;

void backtracking(int depth, int index);
int count_node(int x);
void dfs(int x, int y, int num);
bool is_possible(int x, int y, int d, int n);
int manipulate_bridge(int x, int y, int d, int w);

int main(int argc, char const *argv[])
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];

            if (board[i][j])
                v.push_back(make_pair(i, j));
        }
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (visited[i][j] == false && board[i][j])
                dfs(i, j, ++num);
    
    K = (int) v.size();
    
    backtracking(0, 0);

    if (answer != 10000)
        cout << answer << "\n";
    else
        cout << -1 << "\n";

    return 0;
}

void backtracking(int depth, int index)
{
    if (depth == num - 1)
    {
        fill_n(&selected[0], MAX, false);

        if (count_node(1) == num)
        {   
            int count_bridge = 0;

            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++)
                    count_bridge += bridge[i][j];
            
            answer = min(answer, count_bridge);
        }

        return;
    }

    for (int i = index; i < K; i++)
    {
        int x = v[i].first, y = v[i].second;
        int n = board[x][y];

        for (int d = 0; d < 4; d++)
        {
            if (!is_possible(x, y, d, n))
                continue;
            
            int next_n = manipulate_bridge(x, y, d, 1);
            adj[n][next_n] += 1, adj[next_n][n] += 1;
            backtracking(depth + 1, i);
            adj[n][next_n] -= 1, adj[next_n][n] -= 1;
            manipulate_bridge(x, y, d, -1);
        }
    }
}

int manipulate_bridge(int x, int y, int d, int w)
{
    while (board[x + dx[d]][y + dy[d]] == 0)
    {
        bridge[x + dx[d]][y + dy[d]] += w;
        x += dx[d], y += dy[d];
    }

    return board[x + dx[d]][y + dy[d]];
}

int count_node(int x)
{
    selected[x] = true;
    int ret = 1;

    for (int i = 1; i <= num; i++)
    {
        if (selected[i] || adj[x][i] == 0)
            continue;
        
        ret += count_node(i);
    }

    return ret;
}

bool is_possible(int x, int y, int d, int n)
{
    bool possible = false;
    int w = 0;

    while (true)
    {
        int nx = x + dx[d], ny = y + dy[d];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            break;
        
        if (board[nx][ny])
        {
            if (w >= 2)
                possible = true;
            break;
        }

        w += 1;
        x = nx, y = ny;
    }

    return possible;
}

void dfs(int x, int y, int num)
{
    visited[x][y] = true;
    board[x][y] = num;

    for (int d = 0; d < 4; d++)
    {
        int nx = x + dx[d], ny = y + dy[d];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;
        
        if (visited[nx][ny] || board[nx][ny] == 0)
            continue;
        
        dfs(nx, ny, num);
    }
}



// class union_find
// {
// private:
//     vector<int> parent;

// public:
//     union_find(int N)
//     {
//         parent = vector<int> (N + 1, -1);
//     }

//     int find(int x)
//     {
//         if (parent[x] < 0) return x;

//         int y = find(parent[x]);
//         parent[x] = y;

//         return y;
//     }

//     void merge(int x, int y)
//     {
//         x = find(x), y = find(y);

//         if (x == y) return;

//         if (parent[x] > parent[y]) swap(x, y);

//         parent[x] += parent[y];
//         parent[y] = x;
//     }
// };

// struct edge
// {
//     int u, v, w;

//     bool operator< (const edge &e) const
//     {
//         return w < e.w;
//     }
// };

// const int MAX = 10;
// const int dx[] = { -1, 1, 0, 0 };
// const int dy[] = { 0, 0, -1, 1 };

// int N, M, L, num;
// int board[MAX][MAX];
// bool visited[MAX][MAX];
// bool seleted[MAX];
// vector<edge> edges;

// void find_edge(int x, int y, int d, int num);
// edge make_edge(int u, int v, int w);
// void dfs(int x, int y, int num);

// int main(int argc, char const *argv[])
// {
//     cin >> N >> M;

//     for (int i = 0; i < N; i++)
//         for (int j = 0; j < M; j++)
//             cin >> board[i][j];
    
//     for (int x = 0; x < N; x++)
//         for (int y = 0; y < M; y++)
//             if (board[x][y] && visited[x][y] == false)
//                 dfs(x, y, ++num);
    
//     for (int x = 0; x < N; x++)
//         for (int y = 0; y < M; y++)
//             if (board[x][y] != 0)
//                 for (int d = 0; d < 4; d++)
//                     find_edge(x, y, d, board[x][y]);

//     L = (int) edges.size();
//     sort(edges.begin(), edges.end());

//     union_find *g = new union_find(num);
//     int sum_weight = 0, _count = 0;

//     for (int i = 0; i < L; i++)
//     {
//         if (g->find(edges[i].u) != g->find(edges[i].v))
//         {
//             _count += 1;
//             g->merge(edges[i].u, edges[i].v);
//             sum_weight += edges[i].w;
//         }

//         if (_count == num - 1)
//             break;
//     }

//     delete g;

//     if (sum_weight != 0 && _count == num - 1)
//         cout << sum_weight << "\n";
//     else
//         cout << -1 << "\n";

//     return 0;
// }

// void find_edge(int x, int y, int d, int num)
// {
//     bool is_possible = false;
//     int weight = 0, v = 0;

//     while (true)
//     {
//         int nx = x + dx[d], ny = y + dy[d];

//         if (nx < 0 || nx >= N || ny < 0 || ny >= M)
//             break;
        
//         if (board[nx][ny] == num)
//             break;
        
//         if (board[nx][ny] != 0 && board[nx][ny] != num)
//         {
//             is_possible = true;
//             v = board[nx][ny];
//             break;
//         }

//         weight += 1;
//         x = nx, y = ny;
//     }

//     if (is_possible && weight >= 2)
//         edges.push_back(make_edge(num, v, weight));
// }

// void dfs(int x, int y, int num)
// {
//     visited[x][y] = true;
//     board[x][y] = num;

//     for (int i = 0; i < 4; i++)
//     {
//         int nx = x + dx[i], ny = y + dy[i];

//         if (nx < 0 || nx >= N || ny < 0 || ny >= M)
//             continue;
        
//         if (visited[nx][ny] || board[nx][ny] == 0)
//             continue;
        
//         dfs(nx, ny, num);
//     }
// }

// edge make_edge(int u, int v, int w)
// {
//     edge e = { u, v, w };
//     return e;
// }