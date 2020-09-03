#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

struct edge
{
    int v, w;
};

struct person
{
    int v;
    long long w;
    int k;

    bool operator< (const person &p) const
    {
        if (w != p.w) return w > p.w;
        else if (k != p.k) return k > p.k;
        else return v > p.v;
    }
};

const int MAX_N = 1e4 + 1;
const int MAX_K = 21;

int N, M, K;
vector< vector<edge> > node(MAX_N);

edge make_edge(int v, int w);
person make_person(int v, long long w, int k);
vector< vector<long long> > find_path(int src);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 0; i < M; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        node[u].push_back(make_edge(v, w));
        node[v].push_back(make_edge(u, w));
    }

    vector< vector<long long> > dist = find_path(1);

    long long answer = LONG_LONG_MAX;

    for (int i = 0; i <= K; i++)
        answer = min(answer, dist[N][i]);
    
    cout << answer << "\n";

    return 0;
}

edge make_edge(int v, int w)
{
    edge e = { v, w };
    return e;
}

person make_person(int v, long long w, int k)
{
    person p = { v, w, k };
    return p;
}

vector< vector<long long> > find_path(int src)
{
    vector< vector<long long> > dist(MAX_N, vector<long long> (MAX_K, LONG_LONG_MAX));
    priority_queue<person> pq;
    dist[src][0] = 0;
    pq.push(make_person(src, 0, 0));

    while (!pq.empty())
    {
        int v = pq.top().v, k = pq.top().k;
        long long w = pq.top().w;
        pq.pop();

        if (dist[v][k] < w || k > K)
            continue;
        
        for (vector<edge>::iterator iter = node[v].begin(); iter != node[v].end(); iter++)
        {
            int nv = (*iter).v;
            long long nw = (*iter).w;

            if (dist[nv][k] > nw + w)
            {
                dist[nv][k] = nw + w;
                pq.push(make_person(nv, nw + w, k));
            }

            if (k + 1 <= K && dist[nv][k + 1] > w)
            {
                dist[nv][k + 1] = w;
                pq.push(make_person(nv, w, k + 1));
            }
        }
    }

    return dist;
}