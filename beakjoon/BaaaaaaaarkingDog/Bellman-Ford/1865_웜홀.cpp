#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAX = 501;

struct edge
{
    int v, w;
};

int N, M, W;
vector< vector<edge> > graph(MAX);

edge make_edge(int v, int w);
bool find_negative_cycle(int src);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        for (int i = 0; i < MAX; i++)
            graph[i].clear();

        cin >> N >> M >> W;

        for (int i = 0; i < M; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back(make_edge(v, w));
            graph[v].push_back(make_edge(u, w));
        }

        for (int i = 0; i < W; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back(make_edge(v, -w));
        }

        bool negative_cycle = find_negative_cycle(1);

        negative_cycle == true ? cout << "YES" << "\n" : cout << "NO" << "\n";
    }

    return 0;
}

edge make_edge(int v, int w)
{
    edge e = { v, w };
    return e;
}

bool find_negative_cycle(int src)
{
    vector<long long> dist(N + 1, LONG_LONG_MAX);

    dist[src] = 0;

    for (int k = 1; k <= N - 1; k++)
        for (int u = 1; u <= N; u++)
            for (vector<edge>::iterator iter = graph[u].begin(); iter != graph[u].end(); iter++)
            {
                int v = (*iter).v, w = (*iter).w;

                if (dist[u] != LONG_LONG_MAX && dist[v] > dist[u] + w)
                    dist[v] = dist[u] + w;
            }
    
    for (int u = 1; u <= N; u++)
        for (vector<edge>::iterator iter = graph[u].begin(); iter != graph[u].end(); iter++)
        {
            int v = (*iter).v, w = (*iter).w;

            if (dist[u] != LONG_LONG_MAX && dist[v] > dist[u] + w)
                return true;
        }
    
    return false;
}
