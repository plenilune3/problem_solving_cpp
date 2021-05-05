#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAX = 101;

struct edge
{
    int v, t, m;

    edge(int _v, int _t, int _m) : v(_v), t(_t), m(_m) {}

    bool operator< (const edge e) const
    {
        return m > e.m;
    }
};

int N, L, T, M;
vector< vector<edge> > node(MAX);

int find_weight(int S);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> T >> M >> L;

    while (L--)
    {
        int u, v, t, m; cin >> u >> v >> t >> m;
        node[u].push_back(edge(v, t, m));
        node[v].push_back(edge(u, t, m));
    }

    int answer = find_weight(1);

    cout << answer << "\n";

    return 0;
}

int  find_weight(int S)
{
    vector<int> weight(MAX, INT_MAX);
    vector<int> money(MAX, INT_MAX);
    priority_queue<edge> pq;
    weight[S] = 0, money[S] = 0;
    pq.push(edge(S, 0, 0));

    while (!pq.empty())
    {
        int u = pq.top().v, t = pq.top().t, m = pq.top().m;
        pq.pop();

        if (weight[u] < t && money[u] < m)
            continue;

        for (vector<edge>::iterator i = node[u].begin(); i != node[u].end(); i++)
        {
            int nv = (*i).v, nt = t + (*i).t, nm = m + (*i).m;
            
            if (nt > T || nm > M)
                continue;
           
            if (nm < money[nv]) money[nv] = nm;
            if (nt < weight[nv]) weight[nv] = nt;

            pq.push(edge(nv, nt, nm));
        }
    }

    if (money[N] != INT_MAX)
        return money[N];
    else
        return -1;
}
