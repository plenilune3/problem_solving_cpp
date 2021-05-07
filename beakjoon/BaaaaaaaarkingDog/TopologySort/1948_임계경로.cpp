#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1e4 + 1;

struct edge
{
    int v, w;

    edge(int _v, int _w) : v(_v), w(_w) {}
};

struct path
{
    int v, w, r;

    path(int _v, int _w, int _r) : v(_v), w(_w), r(_r) {}
};

int N, M, S, T;
int D[MAX], W[MAX];
bool visited[MAX];
vector< vector<edge> > node(MAX);
vector< vector<edge> > node_reverse(MAX);

int find_path(int N, int S, int T, vector< vector<edge> > &node);
int count_road(int T);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;
    
    for (int i = 0; i < M; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        node[u].push_back(edge(v, w));
        node_reverse[v].push_back(edge(u, w));
        D[v] += 1;
    }

    cin >> S >> T;

    int weight = find_path(N, S, T, node);
    int road = count_road(T);

    cout << weight << " " << road << "\n";

    return 0;
}

int find_path(int N, int S, int T, vector< vector<edge> > &node)
{
    queue<int> q;

    q.push(S);
   
    for (int i = 1; i <= N; i++)
    {
        int u = q.front();
        q.pop();

        for (vector<edge>::iterator j = node[u].begin(); j != node[u].end(); j++)
        {
            int v = (*j).v, w = (*j).w;

            if (--D[v] == 0)
                q.push(v);
            
            W[v] = max(W[v], W[u] + w);
        }
    }

    return W[T];
}

int count_road(int T)
{
    int result = 0;
    queue<int> q;

    q.push(T);
    visited[T] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (vector<edge>::iterator i = node_reverse[u].begin(); i != node_reverse[u].end(); i++)
        {
            int v = (*i).v, w = (*i).w;

            if (W[u] - w != W[v])
                continue;

            result += 1;

            if (visited[v])
                continue;
            
            visited[v] = true;
            q.push(v);
        }
    }

    return result;
}