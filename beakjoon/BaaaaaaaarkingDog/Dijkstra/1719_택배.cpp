#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <climits>

using namespace std;

struct edge
{
    int v, w;

    bool operator< (const edge &e) const
    {
        if (w != e.w) return w > e.w;
        else return v > e.v;
    }
};

const int MAX = 201;

int N, M;
vector< vector<edge> > node(MAX);

edge make_edge(int v, int w);
vector<int> find_path(int src);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        node[u].push_back(make_edge(v, w));
        node[v].push_back(make_edge(u, w));
    }

    for (int i = 1; i <= N; i++)
    {
        vector<int> trace = find_path(i);

        for (int j = 1; j <= N; j++)
        {
            vector<int> route;

            if (i == j)
            {
                cout << "-" << " ";
                continue;
            }

            int dest = j;

            while (dest)
            {
                route.push_back(dest);
                dest = trace[dest];
            }

            reverse(route.begin(), route.end());

            cout << route[1] << " ";
        }

        cout << "\n";
    }

    return 0;
}

edge make_edge(int v, int w)
{
    edge e = { v, w };
    return e;
}

vector<int> find_path(int src)
{
    vector<int> dist(MAX, INT_MAX), trace(MAX, 0);
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
                dist[nv] = nw + w, trace[nv] = v;
                pq.push(make_edge(nv, nw + w));
            }
        }
    }

    return trace;
}