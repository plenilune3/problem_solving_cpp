#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAX = 5e3 + 1;

struct edge
{
    int v, w;

    bool operator< (const edge &e) const
    {
        if (w != e.w) return w > e.w;
        else return v > e.v;
    }
};

int V, E, P;
vector< vector<edge> > node(MAX);

edge make_edge(int v, int w);
vector<int> find_path(int src);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> V >> E >> P;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        node[u].push_back(make_edge(v, w));
        node[v].push_back(make_edge(u, w));
    }

    vector<int> dist_v = find_path(V);
    vector<int> dist_p = find_path(P);

    if (dist_p[V] != INT_MAX && dist_p[1] + dist_p[V] == dist_v[1])
        cout << "SAVE HIM" << "\n";
    else
        cout << "GOOD BYE" << "\n";

    return 0;
}

edge make_edge(int v, int w)
{
    edge e = { v, w };
    return e;
}

vector<int> find_path(int src)
{
    vector<int> dist(V + 1, INT_MAX);
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