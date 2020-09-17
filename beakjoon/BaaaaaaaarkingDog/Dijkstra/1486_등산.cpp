#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
#include <cmath>

using namespace std;

const int MAX = 25;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

struct edge
{
    int v, w;

    bool operator< (const edge &e) const
    {
        if (w != e.w) return w > e.w;
        else return v > e.v;
    }
};

int N, M, T, D;
int board[MAX][MAX];
vector< vector<edge> > node(MAX * MAX + 1);
vector< vector<edge> > node_reverse(MAX * MAX + 1);

edge make_edge(int v, int w);
int get_weight(int from, int to);
int get_node(int x, int y);
void find_edge(int x, int y);
vector<int> find_path(int src, vector< vector<edge> > &node);

int main(int argc, char const *argv[])
{
    cin >> N >> M >> T >> D;

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        for (int j = 0; j < M; j++)
        {
            if (str[j] >= 'A' && str[j] <= 'Z')
                board[i][j] = str[j] - 'A';
            else
                board[i][j] = str[j] - 'a' + 26;
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            find_edge(i, j);
    
    vector<int> dist_u = find_path(0, node);
    vector<int> dist_d = find_path(0, node_reverse);

    int max_height = board[0][0];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            if (dist_u[get_node(i, j)] == INT_MAX || dist_d[get_node(i, j)] == INT_MAX)
                continue;

            if (dist_u[get_node(i, j)] + dist_d[get_node(i, j)] <= D)
                max_height = max(max_height, board[i][j]);
        }

    cout << max_height << "\n";

    return 0;
}

edge make_edge(int v, int w)
{
    edge e = { v, w };
    return e;
}

int get_weight(int from, int to)
{
    return from < to ? (from - to) * (from - to) : 1;
}

int get_node(int x, int y)
{
    return x * M + y;
}

void find_edge(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;
        
        if (abs(board[x][y] - board[nx][ny]) > T)
            continue;
        
        int u = get_node(x, y), v = get_node(nx, ny), w = get_weight(board[x][y], board[nx][ny]);

        node[u].push_back(make_edge(v, w));
        node_reverse[v].push_back(make_edge(u, w));
    }
}

vector<int> find_path(int src, vector< vector<edge> > &node)
{
    vector<int> dist(N * M + 1, INT_MAX);
    priority_queue<edge> pq;
    dist[src] = 0;
    pq.push(make_edge(src, 0));

    while (!pq.empty())
    {
        int v = pq.top().v, w = pq.top().w;
        pq.pop();

        if (dist[v] < w)
            continue;

        for (vector<edge>::iterator iter = node[v].begin(); iter != node[v].end(); iter++)
        {
            int nv = (*iter).v, nw = (*iter).w;

            if (dist[nv] > nw + w)
            {
                dist[nv] = nw + w;
                pq.push(make_edge(nv, nw + w));
            }
        }
    }

    return dist;
}
