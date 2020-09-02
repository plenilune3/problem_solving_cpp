#include <iostream>
#include <vector>
#include <climits>
#include <queue>

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

const int MAX = 1e4 + 1;

int N, D, C;
vector< vector<edge> > node(MAX);

edge make_edge(int v, int w);
vector<int> hacking(int src);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T;

    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        fill(node.begin(), node.end(), vector<edge>());

        cin >> N >> D >> C;

        for (int i = 0; i < D; i++)
        {
            int u, v, w; cin >> u >> v >> w;
            node[v].push_back(make_edge(u, w));
        }

        vector<int> dist = hacking(C);

        int count = 0, max_dist = INT_MIN;

        for (int i = 1; i <= N; i++)
        {
            if (dist[i] == INT_MAX)
                continue;
            
            max_dist = max(max_dist, dist[i]);
            count += 1;
        }

        cout << count << " " << max_dist << "\n";
    }

    return 0;
}

edge make_edge(int v, int w)
{
    edge e = { v, w };
    return e;
}

vector<int> hacking(int src)
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

            if (w + nw < dist[nv])
            {
                dist[nv] = nw + w;
                pq.push(make_edge(nv, nw + w));
            }
        }
    }

    return dist;
}
