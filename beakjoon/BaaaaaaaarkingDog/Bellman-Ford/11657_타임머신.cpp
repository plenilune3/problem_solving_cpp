#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAX = 501;

struct bus
{
    int dest;
    long long dist;
};

int N, M;
vector< vector<bus> > city(MAX);

bus make_bus(int dest, long long dist);
vector<long long> bellman_ford(int start);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> N >> M;

    while (M--)
    {
        int u, v;
        long long w;

        cin >> u >> v >> w;

        city[u].push_back(make_bus(v, w));
    }

    vector<long long> dist = bellman_ford(1);

    if (dist.size() == 1)
        cout << dist[0] << "\n";
    else
        for (int i = 2; i <= N; i++)
            dist[i] != LONG_LONG_MAX ? cout << dist[i] << "\n" : cout << -1 << "\n";

    return 0;
}

bus make_bus(int dest, long long dist)
{
    bus b = { dest, dist };
    return b;
}

vector<long long> bellman_ford(int start)
{
    vector<long long> dist(N + 1, LONG_LONG_MAX);

    dist[start] = 0;

    for (int k = 1; k <= N - 1; k++)
        for (int u = 1; u <= N; u++)
            for (vector<bus>::iterator iter = city[u].begin(); iter != city[u].end(); iter++)
            {
                int v = (*iter).dest;
                long long w = (*iter).dist;

                if (dist[u] != LONG_LONG_MAX && dist[v] > dist[u] + w)
                    dist[v] = dist[u] + w;
            }
    
    for (int u = 1; u <= N; u++)
    {
        for (vector<bus>::iterator iter = city[u].begin(); iter != city[u].end(); iter++)
        {
            int v = (*iter).dest;
            long long w = (*iter).dist;

            if (dist[u] != LONG_LONG_MAX && dist[v] > dist[u] + w)
                return vector<long long> (1, -1);
        }
    }
    
    return dist;
}
