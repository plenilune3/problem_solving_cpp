#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

const int MAX = 1e6 + 1;

struct edge
{
    int v; long long w;

    bool operator< (const edge &e) const
    {
        if (w != e.w) return w > e.w;
        else return v > e.v;
    }
};

int N, M, K;
int city[MAX];
vector< vector<edge> > node(MAX);

edge make_edge(int v, long long w);
vector<long long> find_path(int city[MAX]);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> N >> M >> K;

    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        node[v].push_back(make_edge(u, w));
    }

    for (int i = 0; i < K; i++)
        cin >> city[i];
    
    vector<long long> dist = find_path(city);

    int max_city = 0;
    long long max_distance = 0;

    for (int i = 1; i <= N; i++)
    {
        if (dist[i] > max_distance)
        {
            max_distance = dist[i];
            max_city = i;
        }
    }

    cout << max_city << "\n";
    cout << max_distance << "\n";
    
    return 0;
}

edge make_edge(int v, long long w)
{
    edge e = { v, w };
    return e;
}

vector<long long> find_path(int city[MAX])
{
    vector<long long> dist(N + 1, LONG_LONG_MAX);
    priority_queue<edge> pq;

    for (int i = 0; i < K; i++)
    {
        dist[city[i]] = 0;
        pq.push(make_edge(city[i], 0));
    }

    while (!pq.empty())
    {
        int v = pq.top().v; long long w = pq.top().w;
        pq.pop();

        if (dist[v] < w)
            continue;

        for (vector<edge>::iterator iter = node[v].begin(); iter != node[v].end(); iter++)
        {
            int nv = (*iter).v; long long nw = (*iter).w;

            if (dist[nv] > nw + w)
            {
                dist[nv] = nw + w;
                pq.push(make_edge(nv, nw + w));
            }
        }
    }

    return dist;
}