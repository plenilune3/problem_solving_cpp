#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

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

const int MAX = 5e2 + 1;

int N, M, S, D;
vector< vector< pair<int, int> > >trace(MAX);
vector< vector<edge> > node(MAX);

edge make_edge(int v, int w);
vector<int> find_path(int src);
void delete_path(int dest);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (true)
    {
        fill(node.begin(), node.end(), vector<edge> ());
        fill(trace.begin(), trace.end(),vector< pair<int, int> > ());
        cin >> N >> M;

        if (N == 0 && M == 0)
            break;
        
        cin >> S >> D;

        for (int i = 0; i < M; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;

            node[u].push_back(make_edge(v, w));
        }

        find_path(S);
        delete_path(D);
        vector<int> dist = find_path(S);

        if (dist[D] != INT_MAX)
            cout << dist[D] << "\n";
        else
            cout << "-1" << "\n";
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
    vector<int> route;
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

            if (nw == -1)
                continue;

            if (dist[nv] > nw + w)
            {
                dist[nv] = nw + w;
                pq.push(make_edge(nv, nw + w));

                trace[nv].clear();
                trace[nv].push_back(make_pair(v, nw));
            }

            else if (dist[nv] == nw + w)
                trace[nv].push_back(make_pair(v, nw));
        }
    }

    return dist;
}

void delete_path(int dest)
{
    bool visited[N][N];
    fill_n(&visited[0][0], N * N, false);
    queue<int> q;
    q.push(dest);

    while (!q.empty())
    {
        int v = q.front(); q.pop();

        for (vector< pair<int, int> >::iterator i = trace[v].begin(); i != trace[v].end(); i++)
        {
            int u = (*i).first;

            if (visited[u][v])
                continue;
            
            visited[u][v] = true;

            for (vector<edge>::iterator j = node[u].begin(); j != node[u].end(); j++)
                if ((*j).v == v)
                {
                    (*j).w = -1;
                    break;
                }

            q.push(u);
        }
    }
}