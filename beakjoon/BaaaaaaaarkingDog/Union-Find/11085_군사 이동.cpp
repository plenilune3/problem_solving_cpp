#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX_N = 1e3 + 1;
const int MAX_M = 5e4 + 1;

struct edge 
{
    int u, v, w;

    bool operator< (const edge &e)
    {
        return w > e.w;
    }
};

int P, W, C, V;
int parent[MAX_N], width[MAX_N];
edge edges[MAX_M];

int find_(int u);
void union_(int u, int v); 

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> P >> W >> C >> V;

    for (int u = 0; u < P; u++)
        parent[u] = u;

    for (int i = 0; i < W; i++)
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    
    sort(&edges[0], &edges[0] + W);

    int answer = INT_MAX;

    for (int i = 0; i < W; i++)
    {
        if (find_(C) == find_(V))
            break;
        
        union_(edges[i].u, edges[i].v);
        answer = min(answer, edges[i].w);
    }

    cout << answer << "\n";

    return 0;
}

int find_(int u)
{
    if (parent[u] == u)
        return u;
    else
    {
        int v = find_(parent[u]);
        return parent[u] = v;
    }
}

void union_(int u, int v)
{
    u = find_(u), v = find_(v);

    if (u == v) return;

    parent[u] = v;
}
