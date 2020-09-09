#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

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

const int MAX = 1e3 + 1;

int N, M;
int trace[MAX];
vector< vector<edge> > node(MAX);

edge make_edge(int v, int w);
vector<int> find_path(int src);
vector< pair<int, int> > find_route(int dest);

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

    vector<int> dist = find_path(1);
    vector< pair<int, int> > route = find_route(N);

    int answer = INT_MIN;

    for (vector< pair<int, int> >::iterator i = route.begin(); i != route.end(); i++)
    {
        int u = (*i).first, v = (*i).second, w;
        vector<edge>::iterator iter;

        for (vector<edge>::iterator j = node[u].begin(); j != node[u].end(); j++)
        {
            if ((*j).v == v)
            {
                iter = j;
                w = (*j).w;
                node[u].erase(j);
                break;
            }
        }

        vector<int> _dist = find_path(1);

        if (_dist[N] == INT_MAX)
        {
            answer = INT_MAX;
            break;
        }
        else
            answer = max(answer, _dist[N] - dist[N]);

        node[u].insert(iter, make_edge(v, w));
    }

    if (answer != INT_MAX)
        cout << answer << "\n";
    else
        cout << -1 << "\n";

    return 0;
}

edge make_edge(int v, int w)
{
    edge e = { v, w };
    return e;
}

vector< pair<int, int> > find_route(int dest)
{
    vector< pair<int, int> > route;

    while (trace[dest])
    {
        route.push_back(make_pair(trace[dest], dest));
        dest = trace[dest];
    }

    reverse(route.begin(), route.end());

    return route;
}

vector<int> find_path(int src)
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
                trace[nv] = v;
                dist[nv] = nw + w;
                pq.push(make_edge(nv, nw + w));
            }
        }
    }

    return dist;
}