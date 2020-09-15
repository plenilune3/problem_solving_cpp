#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1e6 + 1;

class union_find
{
private:
    vector<int> parent;

public:
    union_find(int N)
    {
        parent = vector<int> (N + 1, -1);
    }

    int find(int x)
    {
        if (parent[x] < 0) return x;
        
        int y = find(parent[x]);
        parent[x] = y;

        return y;
    }

    void merge(int x, int y)
    {
        x = find(x), y = find(y);

        if (x == y) return;

        if (parent[x] > parent[y])
            swap(x, y);
        
        parent[x] += parent[y];
        parent[y] = x;
    }
};

struct edge
{
    int u, v, w;

    bool operator< (const edge &e) const
    {
        return w < e.w;
    }
};


int N, M;
edge e[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;
    
    sort(e, e + M);

    union_find g(N);
    int cnt = 0, dist = 0;

    for (int i = 0; i < M; i++)
    {
        if (g.find(e[i].u) != g.find(e[i].v))
        {
            cnt += 1;
            g.merge(e[i].u, e[i].v);
            dist += e[i].w;
        }

        if (cnt == N - 2)
            break;
    }

    cout << dist << "\n";

    return 0;
}

// const int MAX = 1e5 + 1

// struct edge
// {
//     int v, w;

//     bool operator< (const edge& e) const
//     {
//         if (w != e.w) return w > e.w;
//         else return v > e.v;
//     }
// };

// int N, M;
// vector< vector<edge> > node(MAX);

// edge make_edge(int v, int w);
// long long find_mst(int src);

// int main(int argc, char const *argv[])
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL), cout.tie(NULL);

//     cin >> N >> M;

//     while (M--)
//     {
//         int u, v, w;
//         cin >> u >> v >> w;

//         node[u].push_back(make_edge(v, w));
//         node[v].push_back(make_edge(u, w));
//     }

//     cout << find_mst(1) << "\n";

//     return 0;
// }

// edge make_edge(int v, int w)
// {
//     edge e = { v, w };
//     return e;
// }

// long long find_mst(int src)
// {
//     bool visited[N + 1];
//     fill_n(&visited[0], N + 1, false);
//     priority_queue<edge> pq;
//     int max_weight, sum_weight = 0;

//     visited[src] = true;

//     for (vector<edge>::iterator iter = node[src].begin(); iter != node[src].end(); iter++)
//     {
//         int v = (*iter).v, w = (*iter).w;
//         pq.push(make_edge(v, w));
//     }

//     while (!pq.empty())
//     {
//         int v = pq.top().v, w = pq.top().w;
//         pq.pop();

//         if (visited[v])
//             continue;
        
//         visited[v] = true;
//         sum_weight += w;
//         max_weight = max(max_weight, w);

//         for (vector<edge>::iterator iter = node[v].begin(); iter != node[v].end(); iter++)
//         {
//             int nv = (*iter).v, nw = (*iter).w;
//             pq.push(make_edge(nv, nw));
//         }
//     }

//     return sum_weight - max_weight;
// }