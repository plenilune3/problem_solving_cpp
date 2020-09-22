#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

const int MAX = 1e3 + 1;

struct edge
{
    int v, w;

    bool operator< (const edge &e) const
    {
        if (w != e.w) return w > e.w;
        else return v > e.v;
    }
};

int N, M;
int p[3], trace[3][MAX];
vector< vector<edge> > node(MAX);
set< pair<int, int> > links;
vector<int> dist[3];

edge make_edge(int v, int w);
vector<int> find_path(int src, int idx);
vector< pair<int, int> > find_route(int dest, int idx);
int get_links_sum(set< pair<int, int> > &links);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    while (M--)
    {
        int u, v, w; 
        cin >> u >> v >> w;

        node[u].push_back(make_edge(v, w));
        node[v].push_back(make_edge(u, w));
    }

    for (int i = 0; i < 3; i++)
    {
        cin >> p[i];
        dist[i] = find_path(p[i], i);
    }

    int min_sum = INT_MAX, min_vertex;

    for (int i = 1; i <= N; i++)
    {
        set< pair<int, int> > temp;

        for (int j = 0; j < 3; j++)
        {
            vector< pair<int, int> > route = find_route(i, j);

            for (vector< pair<int, int> >::iterator iter = route.begin(); iter != route.end(); iter++)
            {
                int u = (*iter).first, v = (*iter).second;

                if (u > v) swap(u, v);

                temp.insert(make_pair(u, v));
            }
        }

        int sum = get_links_sum(temp);

        if (sum < min_sum)
        {
            min_sum = sum;
            links = temp;
        }
    }

    cout << min_sum << " " << links.size() << "\n";

    for (set< pair<int, int> >::iterator iter = links.begin(); iter != links.end(); iter++)
        cout << (*iter).first << " " << (*iter).second << "\n";

    return 0;
}

edge make_edge(int v, int w)
{
    edge e = { v, w };
    return e;
}

vector<int> find_path(int src, int idx)
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
                trace[idx][nv] = v;
                pq.push(make_edge(nv, nw + w));
            }
        }
    }

    return dist;
}

vector< pair<int, int> > find_route(int dest, int idx)
{
    vector< pair<int, int> > route;

    while (trace[idx][dest])
    {
        route.push_back(make_pair(trace[idx][dest], dest));
        dest = trace[idx][dest];
    }

    reverse(route.begin(), route.end());

    return route;
}

int get_links_sum(set< pair<int, int> > &links)
{
    int sum_weight = 0;

    for (set< pair<int, int> >::iterator i = links.begin(); i != links.end(); i++)
    {
        int u = (*i).first, v = (*i).second;

        for (vector<edge>::iterator j = node[u].begin(); j != node[u].end(); j++)
            if ((*j).v == v)
            {
                sum_weight += (*j).w;
                break;
            }
    }

    return sum_weight;
}