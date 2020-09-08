#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

struct edge
{
    int v, w;
};

struct fox
{
    int v; long long w;

    bool operator< (const fox& f) const
    {
        if (w != f.w) return w > f.w;
        else return v > f.v;
    }
};

struct wolf
{
    int v; long long w; bool spurt;

    bool operator< (const wolf& e) const
    {
        if (w != e.w) return w > e.w;
        else if (v != e.w ) return v > e.v;
        else return !spurt;
    }
};

const int MAX = 4e3 + 1;

int N, M;
vector< vector<edge> > node(MAX);

edge make_edge(int v, int w);
fox make_fox(int v, long long w);
wolf make_wolf(int v, long long w, bool spurt);
vector<long long> find_fox_path(int src);
vector< vector<long long> > find_wolf_path(int src);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        node[u].push_back(make_edge(v, w));
        node[v].push_back(make_edge(u, w));
    }

    vector<long long> dist_fox = find_fox_path(1);
    vector< vector<long long> > dist_wolf = find_wolf_path(1);

    int answer = 0;
    for (int i = 2; i <= N; i++)
    {
        if (dist_fox[i] < min(dist_wolf[i][0], dist_wolf[i][1]))
            answer += 1;
    }
    
    cout << answer << "\n";

    return 0;
}

edge make_edge(int v, int w)
{
    edge e = { v, w };
    return e;
}

fox make_fox(int v, long long w)
{
    fox f = { v, w };
    return f;
}

wolf make_wolf(int v, long long w, bool spurt)
{
    wolf wo = { v, w, spurt };
    return wo;
}

vector<long long> find_fox_path(int src)
{
    vector<long long> dist(N + 1, LONG_LONG_MAX);
    priority_queue<fox> pq;
    dist[src] = 0;
    pq.push(make_fox(src, 0));

    while (!pq.empty())
    {
        int v = pq.top().v; long long w = pq.top().w;
        pq.pop();

        if (dist[v] < w)
            continue;

        for (vector<edge>::iterator iter = node[v].begin(); iter != node[v].end(); iter++)
        {
            int nv = (*iter).v; long long nw = (*iter).w;

            if (dist[nv] > nw * 2 + w)
            {
                dist[nv] = nw * 2 + w;
                pq.push(make_fox(nv, nw * 2 + w));
            }
        }
    }

    return dist;
}

vector< vector<long long> > find_wolf_path(int src)
{
    vector< vector<long long> > dist(N + 1, vector<long long> (2, LONG_LONG_MAX));
    priority_queue<wolf> pq;
    dist[src][1] = 0;
    pq.push(make_wolf(src, 0, 1));

    while (!pq.empty())
    {
        int v = pq.top().v; long long w = pq.top().w; bool spurt = pq.top().spurt;
        pq.pop();

        if (dist[v][spurt] < w)
            continue;

        for (vector<edge>::iterator iter = node[v].begin(); iter != node[v].end(); iter++)
        {
            int nv = (*iter).v; long long nw = spurt ? (*iter).w : (*iter).w * 4;

            if (dist[nv][!spurt] > nw + w)
            {
                dist[nv][!spurt] = nw + w;
                pq.push(make_wolf(nv, nw + w, !spurt));
            }
        }
    }

    return dist;
}