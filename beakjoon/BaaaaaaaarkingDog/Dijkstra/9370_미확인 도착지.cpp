#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <set>

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

const int MAX = 2e3 + 1;

int N, M, T;
int S, G, H;
int candidate[100];
vector< vector<edge> > node(MAX);

edge make_edge(int v, int w);
vector<int> find_path(int src);
set<int> find_candidate(int S, int G, int H);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int C;
    cin >> C;

    for (int c = 1; c <= C; c++)
    {
        fill(node.begin(), node.end(), vector<edge> ());
        fill_n(&candidate[0], 100, 0);

        cin >> N >> M >> T;
        cin >> S >> G >> H;

        for (int i = 0; i < M; i++)
        {
            int u, v, w; cin >> u >> v >> w;
            node[u].push_back(make_edge(v, w));
            node[v].push_back(make_edge(u, w));
        }

        for (int i = 0; i < T; i++)
            cin >> candidate[i];
        
        set<int> answer = find_candidate(S, G, H);
        
        for (set<int>::iterator iter = answer.begin(); iter != answer.end(); iter++)
            cout << (*iter) << " ";
        cout << "\n";
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

set<int> find_candidate(int S, int G, int H)
{
    set<int> result;

    vector<int> dist_S = find_path(S);
    vector<int> dist_G = find_path(G);
    vector<int> dist_H = find_path(H);

    for (int i = 0; i < T; i++)
    {
        int min_distance = dist_S[candidate[i]];
        int distance_A = dist_S[G] + dist_G[H] + dist_H[candidate[i]];
        int distance_B = dist_S[H] + dist_H[G] + dist_G[candidate[i]];

        if (distance_A == min_distance)
            result.insert(candidate[i]);
        
        if (distance_B == min_distance)
            result.insert(candidate[i]);
    }

    return result;
}
