#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1e4 + 1;

struct edge
{
    int v, w;

    bool operator< (const edge &e) const
    {
        if (w != e.w) return w > e.w;
        else return v > e.v;
    }
};

int V, E;
vector< vector<edge> > node(MAX);
priority_queue<edge> pq;
bool visited[MAX];

edge make_edge(int v, int w);
int prim(int src);

int main(int argc, char const *argv[])
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> V >> E;

    for (int i = 0; i < E; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        node[u].push_back(make_edge(v, w));
        node[v].push_back(make_edge(u, w));
    }

    cout << prim(1) << "\n";

    return 0;
}

edge make_edge(int v, int w)
{
    edge e = { v, w };
    return e;
}

int prim(int src)
{
    visited[src] = true;

    for (int i = 0; i < node[src].size(); i++)
    {
        int v = node[src][i].v, w = node[src][i].w;
        pq.push(make_edge(v, w));
    }

    int answer = 0;

    while (!pq.empty())
    {
        int v = pq.top().v, w = pq.top().w;
        pq.pop();

        if (visited[v])
            continue;

        visited[v] = true;

        answer += w;

        for (vector<edge>::iterator iter = node[v].begin(); iter != node[v].end(); iter++)
        {
            int nv = (*iter).v, nw = (*iter).w;
            pq.push(make_edge(nv, nw));
        }
    }

    return answer;
}

