#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

const int MAX = 800;

struct edge
{
    int dist, num;
};

bool operator<(edge a, edge b)
{
    return a.dist > b.dist;
}

vector<edge> adj[MAX + 1];

edge make_edge(int dist, int num);
vector<int> find_shortest_path(int start_node);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, E, A, B;

    cin >> N >> E;

    while (E--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back(make_edge(w, v));
        adj[v].push_back(make_edge(w, u));
    }

    cin >> A >> B;

    vector<int> A_dist = find_shortest_path(A);
    vector<int> B_dist = find_shortest_path(B);

    int first, second;

    if (A_dist[1] == INT_MAX || A_dist[B] == INT_MAX || A_dist[N] == INT_MAX)
        first = INT_MAX;
    else
        first = A_dist[1] + A_dist[B] + B_dist[N];
    
    if (B_dist[1] == INT_MAX || B_dist[A] == INT_MAX || A_dist[B] == INT_MAX)
        second = INT_MAX;
    else
        second = B_dist[1] + B_dist[A] + A_dist[N];
    
    if (first == INT_MAX || second == INT_MAX)
        cout << -1 << "\n";
    else
        cout << min(first, second) << "\n";

    return 0;
}

edge make_edge(int dist, int num)
{
    return { dist, num };
}

vector<int> find_shortest_path(int start_node)
{
    vector<int> dist(MAX + 1, INT_MAX);
    priority_queue<edge> pq;
    dist[start_node] = 0;
    pq.push(make_edge(0, start_node));

    while (!pq.empty())
    {
        int d = pq.top().dist, n = pq.top().num;
        pq.pop();

        if (d > dist[n])
            continue;
        
        for (vector<edge>::iterator iter = adj[n].begin(); iter != adj[n].end(); iter++)
        {
            int nd = (*iter).dist, nn = (*iter).num;

            if (d + nd < dist[nn])
            {
                dist[nn] = d + nd;
                pq.push(make_edge(d + nd, nn));
            }
        }
    }

    return dist;
}