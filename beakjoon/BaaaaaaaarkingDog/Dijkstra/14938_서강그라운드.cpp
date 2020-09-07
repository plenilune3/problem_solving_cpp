#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

const int MAX = 101;

struct edge
{
    int v, w;

    bool operator< (const edge &e) const
    {
        if (w != e.w) return w > e.w;
        else return v > e.v;
    }
};

int N, M, R, answer = INT_MIN;
int items[MAX];
vector< vector<edge> > node(MAX);

edge make_edge(int v, int w);
vector<int> find_path(int src);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> R;

    for (int i = 1; i <= N; i++)
        cin >> items[i];
    
    for (int i = 1; i <= R; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        node[u].push_back(make_edge(v, w));
        node[v].push_back(make_edge(u, w));
    }

    for (int i = 1; i <= N; i++)
    {
        vector<int> dist = find_path(i);
        
        int sum_items = 0;

        for (int j = 1; j <= N; j++)
            if (dist[j] <= M)
                sum_items += items[j];
        
        answer = max(answer, sum_items);
    }

    cout << answer << "\n";

    return 0;
}

edge make_edge(int v, int w)
{
    edge e = { v, w };
    return e;
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
                dist[nv] = nw + w;
                pq.push(make_edge(nv, nw + w));
            }
        }
    }

    return dist;
}
