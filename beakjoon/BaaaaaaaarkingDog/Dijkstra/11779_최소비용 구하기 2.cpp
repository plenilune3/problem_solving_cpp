#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1001;

struct bus
{
    int cost, num;

    bool operator<(const bus &b) const
    {
        return cost > b.cost;
    }
};

int trace[MAX];
vector< vector<bus> > city(MAX);
vector<int> find_route(int T);

bus make_bus(int cost, int num);
vector<int> find_minimum_cost(bus s);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int N, M, S, T;

    cin >> N >> M;

    while (M--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        city[u].push_back(make_bus(w, v));
    }

    cin >> S >> T;

    bus s = make_bus(0, S);

    vector<int> dist = find_minimum_cost(s);
    vector<int> route = find_route(T);

    cout << dist[T] << "\n";
    cout << route.size() << "\n";

    for (vector<int>::iterator iter = route.begin(); iter != route.end(); iter++)
        cout << (*iter) << " ";

    cout << "\n";

    return 0;
}

bus make_bus(int cost, int num)
{
    return { cost, num };
}

vector<int> find_minimum_cost(bus s)
{
    vector<int> dist(MAX, INT_MAX);
    priority_queue<bus> pq;
    dist[s.num] = s.cost;
    pq.push(make_bus(s.cost, s.num));

    while (!pq.empty())
    {
        int c = pq.top().cost, n = pq.top().num;
        pq.pop();

        if (c > dist[n])
            continue;
        
        for (vector<bus>::iterator iter = city[n].begin(); iter != city[n].end(); iter++)
        {
            int nc = (*iter).cost, nn = (*iter).num;

            if (c + nc < dist[nn])
            {
                trace[nn] = n;
                dist[nn] = c + nc;
                pq.push(make_bus(c + nc, nn));
            }
        }
    }

    return dist;
}

vector<int> find_route(int T)
{
    vector<int> route;

    while (T)
    {
        route.push_back(T);
        T = trace[T];
    }

    reverse(route.begin(), route.end());

    return route;
}

