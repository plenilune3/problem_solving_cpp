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

int N, M, K;
vector< vector<edge> > node(MAX);
int f[MAX];

edge make_edge(int v, int w);
vector<int> find_path(int src);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        fill(node.begin(), node.end(), vector<edge> ());
        cin >> N >> M;

        for (int i = 0; i < M; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            node[u].push_back(make_edge(v, w));
            node[v].push_back(make_edge(u, w));
        }

        cin >> K;

        for (int i = 0; i < K; i++)
            cin >> f[i];
        
        int min_distance = INT_MAX;
        int answer;

        for (int i = 1; i <= N; i++)
        {
            vector<int> dist = find_path(i);

            int sum_distance = 0;
            
            for (int j = 0; j < K; j++)
                sum_distance += dist[f[j]];
            
            if (sum_distance < min_distance)
            {
                min_distance = sum_distance;
                answer = i;
            }
        }

        cout << answer << "\n";
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

        for (vector<edge>::iterator i = node[v].begin(); i != node[v].end(); i++)
        {
            int nv = (*i).v, nw = (*i).w;

            if (dist[nv] > nw + w)
            {
                dist[nv] = nw + w;
                pq.push(make_edge(nv, nw + w));
            }
        }
    }

    return dist;
}