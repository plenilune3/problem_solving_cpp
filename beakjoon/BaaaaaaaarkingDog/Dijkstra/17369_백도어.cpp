#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAX = 1e5;

struct edge
{
    int v; long long w;

    bool operator< (const edge &e) const
    {
        if (w != e.w) return w > e.w;
        else return v > e.v;
    }
};

int N, M;
vector< vector<edge> > node(MAX);
bool sight[MAX];

edge make_edge(int v, long long w);
vector<long long> find_path(int src);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> sight[i];

    for (int i = 0; i < M; i++)
    {
        int u, v, w; cin >> u >> v >> w;

        node[u].push_back(make_edge(v, w));
        node[v].push_back(make_edge(u, w));
    }

    vector<long long> dist = find_path(0);

    if (dist[N - 1] != LONG_LONG_MAX)
        cout << dist[N - 1] << "\n";
    else
        cout << -1 << "\n";

    return 0;
}

edge make_edge(int v, long long w)
{
    edge e = { v, w };
    return e;
}

vector<long long> find_path(int src)
{
    vector<long long> dist(MAX, LONG_LONG_MAX);
    priority_queue<edge> pq;
    dist[src] = 0;
    pq.push(make_edge(src, 0));

    while (!pq.empty())
    {
        int v = pq.top().v; long long w = pq.top().w;
        pq.pop();

        if (dist[v] < w)
            continue;

        for (vector<edge>::iterator iter = node[v].begin(); iter != node[v].end(); iter++)
        {
            int nv = (*iter).v, nw = (*iter).w;

            if (dist[nv] > nw + w)
            {
                if (nv == N - 1)
                {
                    dist[nv] = nw + w;
                    pq.push(make_edge(nv, nw + w));
                }
                else if (sight[nv] == 0)
                {
                    dist[nv] = nw + w;
                    pq.push(make_edge(nv, nw + w));
                }
            }
        }
    }

    return dist;
}