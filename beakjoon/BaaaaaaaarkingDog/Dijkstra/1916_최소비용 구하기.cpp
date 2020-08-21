#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1000;

struct bus
{
    int cost, destination;
};

bool operator<(bus a, bus b)
{
    return a.cost > b.cost;
}

bus make_bus(int cost, int destination);
void find_minimum_cost(int start_city);

int cost[MAX + 1];
vector<bus> city[MAX + 1];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, S, D;

    cin >> N >> M;

    while (M--)
    {
        int u, v, w;
        cin >> u >> v >> w;

        city[u].push_back(make_bus(w, v));
    }

    cin >> S >> D;

    find_minimum_cost(S);

    cout << cost[D] << "\n";

    return 0;
}

bus make_bus(int cost, int destination)
{
    bus b = { cost, destination };
    return b;
}

void find_minimum_cost(int start_city)
{
    fill_n(&cost[0], MAX + 1, INT_MAX);
    priority_queue<bus> pq;
    cost[start_city] = 0;
    pq.push(make_bus(0, start_city));

    while (!pq.empty())
    {
        int now_cost = pq.top().cost, now_city = pq.top().destination;
        pq.pop();

        if (now_cost > cost[now_city])
            continue;

        for (vector<bus>::iterator iter = city[now_city].begin(); iter != city[now_city].end(); iter++)
        {
            int next_cost = now_cost + (*iter).cost, next_city = (*iter).destination;

            if (next_cost < cost[next_city])
            {
                cost[next_city] = next_cost;
                pq.push(make_bus(next_cost, next_city));
            }
        }
    }
}
