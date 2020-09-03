#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct edge
{
    int v, c, d;

    bool operator< (const edge &e) const
    {
        if (d != e.d) return d > e.d;
        else if (c != e.c) return c > e.c;
        else return v > e.v;
    }
};

const int MAX = 101;

int N, M, K;
vector< vector<edge> > node(MAX);

edge make_edge(int v, int c, int d);
vector< vector<int> > find_path(int src);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        fill(node.begin(), node.end(), vector<edge>());
        cin >> N >> M >> K;

        for (int i = 0; i < K; i++)
        {
            int u, v, c, d;
            cin >> u >> v >> c >> d;
            node[u].push_back(make_edge(v, c, d));
        }

        vector< vector<int> > dist = find_path(1);

        int min_distance = INT_MAX;

        for (vector<int>::iterator iter = dist[N].begin(); iter != dist[N].end(); iter++)
            if ((*iter) != INT_MAX)
                min_distance = min(min_distance, (*iter));
        
        if (min_distance != INT_MAX)
            cout << min_distance << "\n";
        else
            cout << "Poor KCM" << "\n";
    }

    return 0;
}

edge make_edge(int v, int c, int d)
{
    edge e = { v, c, d };
    return e;
}

vector< vector<int> > find_path(int src)
{
    vector< vector<int> > dist(N + 1, vector<int> (M + 1, INT_MAX));
    priority_queue<edge> pq;
    dist[src][0] = 0;
    pq.push(make_edge(src, 0, 0));

    while (!pq.empty())
    {
        int v = pq.top().v, c = pq.top().c, d = pq.top().d;
        pq.pop();

        if (dist[v][c] < d || c > M)
            continue;

        for (vector<edge>::iterator iter = node[v].begin(); iter != node[v].end(); iter++)
        {
            int nv = (*iter).v, nc = (*iter).c, nd = (*iter).d;

            if (nc + c <= M && dist[nv][nc + c] > nd + d)
            {
                dist[nv][nc + c] = nd + d;
                pq.push(make_edge(nv, nc + c, nd + d));
            }
        }
    }

    return dist;
}

