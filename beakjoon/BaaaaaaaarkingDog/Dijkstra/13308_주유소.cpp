#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

const int MAX = 2501;

struct edge
{
    int v, w;
};

struct car
{
    int v;
    long long w;
    int p;

    bool operator< (const car &c) const
    {
        if (w != c.w) return w > c.w;
        else if (p != c.p) return p > c.p;
        else return v > c.v;
    }
};

int N, M;
int gas_price[MAX];
vector< vector<edge> > node(MAX);

edge make_edge(int v, int w);
car make_car(int v, long long w, int p);
long long find_path(car c);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        cin >> gas_price[i];
    
    for (int i = 0; i < M; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        node[u].push_back(make_edge(v, w));
        node[v].push_back(make_edge(u, w));
    }

    long long answer = find_path(make_car(1, 0, gas_price[1]));

    cout << answer << "\n";

    return 0;
}

edge make_edge(int v, int w)
{
    edge e = { v, w };
    return e;
}

car make_car(int v, long long w, int p)
{
    car c = { v, w, p };
    return c;
}

long long find_path(car c)
{
    vector< vector<long long> > dist(MAX, vector<long long> (MAX, LONG_LONG_MAX));
    priority_queue<car> pq;
    dist[c.v][c.p] = 0;
    pq.push(c);

    while (!pq.empty())
    {
        int v = pq.top().v, p = pq.top().p;
        long long w = pq.top().w;
        pq.pop();

        if (dist[v][p] < w)
            continue;
        
        if (v == N)
            return w;

        for (vector<edge>::iterator iter = node[v].begin(); iter != node[v].end(); iter++)
        {
            int nv = (*iter).v, np = min(p, gas_price[nv]);
            long long nw = (*iter).w;

            if (dist[nv][np] > w + p * nw)
            {
                dist[nv][np] = w + p * nw;
                pq.push(make_car(nv, w + p * nw, np));
            }
        }
    }

    return -1;
}
    
