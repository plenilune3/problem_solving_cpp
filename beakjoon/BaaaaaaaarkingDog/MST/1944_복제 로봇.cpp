#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class union_find
{
private:
    vector<int> parent;
public:
    union_find(int N)
    {
        parent = vector<int> (N + 1, -1);
    }

    int find(int u)
    {
        if (parent[u] < 0) return u;

        int v = find(parent[u]);
        parent[u] = v;

        return v;
    }

    void merge(int u, int v)
    {
        u = find(u), v = find(v);

        if (u == v) return;

        if (parent[u] > parent[v]) swap(u, v);

        parent[u] += parent[v];
        parent[v] = u;
    }
};

struct edge
{
    int u, v, w;

    bool operator<(const edge & e) const
    {
        return w < e.w;
    }
};

const int MAX_N = 50;
const int MAX_M = 250;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N, M;
char board[MAX_N][MAX_N];
vector<edge> edges;

vector< vector<int> > bfs(pair<int, int> src);
edge make_edge(int u, int v, int w);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    vector< pair<int, int> > nodes;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string row;
        cin >> row;

        for (int j = 0; j < N; j++)
        {
            board[i][j] = row[j];
            if (board[i][j] == 'S' || board[i][j] == 'K')
                nodes.push_back(make_pair(i, j));
        }
    }
    
    int length_nodes = nodes.size();

    for (int u = 0; u < length_nodes; u++)
    {
        vector< vector<int> > dist = bfs(nodes[u]);

        for (int v = u + 1; v < length_nodes; v++)
        {
            edge e = make_edge(u, v, dist[nodes[v].first][nodes[v].second]);
            edges.push_back(e);
        }
    }
    
    int length_edges = edges.size();
    sort(edges.begin(), edges.end());

    union_find *g = new union_find(M + 1);
    int cnt = 0, sum_weight = 0;

    for (vector<edge>::iterator iter = edges.begin(); iter != edges.end(); iter++)
    {
        if (cnt == M)
            break;
        
        if ((*iter).w == -1)
        {
            sum_weight = -1;
            break;
        }
        
        if (g->find((*iter).u) != g->find((*iter).v))
        {
            cnt += 1;
            g->merge((*iter).u, (*iter).v);
            sum_weight += (*iter).w;
        }
    }

    cout << sum_weight << "\n";

    return 0;
}

edge make_edge(int u, int v, int w)
{
    edge e = { u, v, w };
    return e;
}

vector< vector<int> > bfs(pair<int, int> src)
{
    vector< vector<int> > dist(N, vector<int> (N, -1));
    queue< pair<int, int> > q;
    dist[src.first][src.second] = 0;
    q.push(src);

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            
            if (board[nx][ny] == '1' || dist[nx][ny] != -1)
                continue;
            
            dist[nx][ny] = dist[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }

    return dist;
}
