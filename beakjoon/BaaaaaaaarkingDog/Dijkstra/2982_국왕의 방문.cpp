#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

const int MAX = 1e3 + 1;

struct edge
{
    int v, w;

    bool operator< (const edge &e) const
    {
        if (w != e.w) return w > e.w;
        return v > e.v;
    }
};

int N, M;
int A, B, K, G;
int route_king[MAX];
pair<int, int> forbid[MAX][MAX];
vector< vector<edge> > node(MAX);

edge make_edge(int v, int w);
vector<int> find_path(int src);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;
    cin >> A >> B >> K >> G;

    for (int i = 0; i < G; i++)
        cin >> route_king[i];

    while (M--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        node[u].push_back(make_edge(v, w));
        node[v].push_back(make_edge(u, w));
    }

    int start = 0;
    for (int i = 0; i < G - 1; i++)
    {
        int u = route_king[i], v = route_king[i + 1];
        int w;

        for (vector<edge>::iterator iter = node[u].begin(); iter != node[u].end(); iter++)
            if ((*iter).v == v)
            {
                w = (*iter).w;
                break;
            }
        
        forbid[u][v] = make_pair(start, start + w);
        forbid[v][u] = make_pair(start, start + w);
        start += w;
    }

    vector<int> dist = find_path(A);

    cout << dist[B] - K << "\n";

    return 0;
}

edge make_edge(int v, int w)
{
    edge e = { v, w };
    return e;
}

vector<int> find_path(int src)
{
    vector<int> dist(N + 1, INT_MAX);
    priority_queue<edge> pq;
    dist[src] = K;
    pq.push(make_edge(src, K));

    while (!pq.empty())
    {
        int v = pq.top().v, w = pq.top().w;
        pq.pop();

        if (dist[v] < w)
            continue;
        
        for (vector<edge>::iterator iter = node[v].begin(); iter != node[v].end(); iter++)
        {
            int nv = (*iter).v, nw = (*iter).w;

            pair<int, int> f = forbid[v][nv];

            if (w >= f.first && w <= f.second)
                nw += f.second - w;

            if (dist[nv] > nw + w)
            {
                dist[nv] = nw + w;
                pq.push(make_edge(nv, nw + w));
            }
        }
    }

    return dist;
}
