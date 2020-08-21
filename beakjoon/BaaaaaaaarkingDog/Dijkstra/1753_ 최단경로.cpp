#include <iostream>
#include <climits>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 20000;
const int INF = 10e6;

struct node
{
    int dist, num;
};

bool operator<(node a, node b)
{
    return a.dist > b.dist;
}

vector< node > graph[MAX + 1];

int V, E, K;
int dist[MAX + 1];

node make_node(int dist, int num);
void find_shortest_path(int node);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> V >> E;
    cin >> K;

    while (E--)
    {
        int u, v, w;

        cin >> u >> v >> w;

        graph[u].push_back(make_node(w, v));
    }

    find_shortest_path(K);

    for (int i = 1; i <= V; i++)
    {
        if (i == K)
            cout << 0 << "\n";
        else
            dist[i] != INT_MAX ? cout << dist[i] << "\n" : cout << "INF" << "\n";
    }

    return 0;
}

node make_node(int dist, int num)
{
    node n = { dist, num };
    return n;
}

void find_shortest_path(int start_node) 
{
    fill_n(&dist[0], MAX + 1, INT_MAX);
    priority_queue<node> pq;
    dist[start_node] = 0;
    pq.push(make_node(0, start_node));

    while(!pq.empty())
    {
        int n = pq.top().num, d = pq.top().dist;
        pq.pop();

        if (d > dist[n])
            continue;
        
        for (vector<node>::iterator iter = graph[n].begin(); iter != graph[n].end(); iter++)
        {
            int next_node = (*iter).num, next_dist = d + (*iter).dist;

            if (next_dist < dist[next_node])
            {
                dist[next_node] = next_dist;
                pq.push(make_node(next_dist, next_node));
            }
        }
    }
}