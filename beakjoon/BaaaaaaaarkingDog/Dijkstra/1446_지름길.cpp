#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

const int MAX = 1e4 + 1;

struct edge
{
    int v, w;

    bool operator< (const edge &e) const
    {
        if (w != e.w) return w > e.w;
        else return v > e.w;
    }
};


int N, D;
vector< vector<edge> > node(MAX);

edge make_edge(int v, int w);
vector<int> find_path(int src);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> D;

    for (int i = 0; i < N; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        if (v <= D)
            node[u].push_back(make_edge(v, w));
    }

    vector<int> dist = find_path(0);

    cout << dist[D] << "\n";

    return 0;
}

edge make_edge(int v, int w)
{
    edge e = { v, w };
    return e;
}

vector<int> find_path(int src)
{
    vector<int> dist(D + 1, INT_MAX);
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

        if (v < D && dist[v + 1] > w + 1)
        {
            dist[v + 1] = w + 1;
            pq.push(make_edge(v + 1, w + 1));
        }
    }

    return dist;
}