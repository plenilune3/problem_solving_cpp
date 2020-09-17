#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

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
vector< vector<int> > trace(MAX);
vector< vector<edge> > node(MAX);

edge make_edge(int v, int w);
void find_path(int src);
vector< pair<int, int> > find_route();

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        
        node[u].push_back(make_edge(v, w));
        node[v].push_back(make_edge(u, w));
    }

    find_path(1);
    vector< pair<int, int> > route = find_route();

    cout << route.size() << "\n";

    for (vector< pair<int, int> >::iterator iter = route.begin(); iter != route.end(); iter++)
        cout << (*iter).first << " " << (*iter).second << "\n";

    return 0;
}

edge make_edge(int v, int w)
{
    edge e = { v, w };
    return e;
}

void find_path(int src)
{
    vector<int> dist(N + 1, INT_MAX);
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

                trace[nv].clear();
                trace[nv].push_back(v);
            }
        }
    }
}

vector< pair<int, int> > find_route()
{
    vector< pair<int, int> > route;

    for (int i = 1; i <= N; i++)
        for (vector<int>::iterator j = trace[i].begin(); j != trace[i].end(); j++)
            route.push_back(make_pair((*j), i));
        
    return route;
}