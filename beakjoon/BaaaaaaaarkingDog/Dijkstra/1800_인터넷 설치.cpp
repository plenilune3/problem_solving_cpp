#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

const int MAX = 1e3 + 1;

struct edge
{
    int v, w;
};

struct link
{
    int v;
    long long w;
    int k;

    bool operator< (const link &l) const
    {
        if (w != l.w) return w > l.w;
        else if (k != l.k) return k > l.k;
        else return v > l.v;
    }
};


int N, P, K;
vector< vector<edge> > node(MAX);

edge make_edge(int v, int w);
long long find_path(int src);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> P >> K;

    for (int i = 0; i < P; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        node[u].push_back(make_edge(v, w));
        node[v].push_back(make_edge(u, w));
    }

    int answer = find_path(1);

    cout << answer << "\n";

    return 0;
}

edge make_edge(int v, int w)
{
    edge e = { v, w };
    return e;
}

link make_link(int v, long long w, int k)
{
    link l = { v, w, k };
    return l;
}

long long find_path(int src)
{
    vector< vector<long long> > dist(N + 1, vector<long long> (K + 1, LONG_LONG_MAX));
    priority_queue<link> pq;
    dist[src][0] = 0;
    pq.push(make_link(src, 0, 0));

    while (!pq.empty())
    {
        int v = pq.top().v, k = pq.top().k;
        long long w = pq.top().w;
        pq.pop();

        if (dist[v][k] < w)
            continue;

        if (v == N)
            return dist[v][k];

        for (vector<edge>::iterator iter = node[v].begin(); iter != node[v].end(); iter++)
        {
            int nv = (*iter).v, nk = k + 1;
            long long nw = (*iter).w;

            if (dist[nv][k] > max(nw, w))
            {
                dist[nv][k] = max(nw, w);
                pq.push(make_link(nv, max(nw, w), k));
            }

            if (nk <= K && dist[nv][nk] > w)
            {
                dist[nv][nk] = w;
                pq.push(make_link(nv, w, nk));
            }
        }
    }

    return -1;
}