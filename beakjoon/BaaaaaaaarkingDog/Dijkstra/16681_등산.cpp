#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

const int MAX = 1e5 + 1;

struct edge
{
    int v;
    long long w;

    bool operator< (const edge &e) const
    {
        if (w != e.w) return w > e.w;
        else return v > e.v;
    }
};

int N, M, D, E;
vector< vector<edge> > node(MAX);
int height[MAX];

edge make_edge(int v, long long w);
vector<long long> find_path(int src);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> D >> E;

    for (int i = 1; i <= N; i++)
        cin >> height[i];
    
    for (int i = 0; i < M; i++)
    {
        int u, v; long long w; cin >> u >> v >> w;
        node[u].push_back(make_edge(v, w));
        node[v].push_back(make_edge(u, w));
    }

    vector<long long> up_dist = find_path(1);
    vector<long long> down_dist = find_path(N);

    long long answer = LONG_LONG_MIN;

    for (int i = 1; i <= N; i++)
    {
        long long achievement = height[i] * E;

        if (up_dist[i] == LONG_LONG_MAX || down_dist[i] == LONG_LONG_MAX)
            continue;
        
        answer = max(answer, achievement - (up_dist[i] + down_dist[i]));
    }

    if (answer != LONG_LONG_MIN)
        cout << answer << "\n";
    else
        cout << "Impossible" << "\n";

    return 0;
}

edge make_edge(int v, long long w)
{
    edge e = { v, w };
    return e;
}

vector<long long> find_path(int src)
{
    vector<long long> dist(N + 1, LONG_LONG_MAX);
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
            int nv = (*iter).v; long long nw = (*iter).w;

            if (height[nv] > height[v] && dist[nv] > nw * D + w)
            {
                dist[nv] = nw * D + w;
                pq.push(make_edge(nv, nw * D + w));
            }
        }
    }

    return dist;
}