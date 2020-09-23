#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class union_find
{
private:
    vector<int> parent;
public:
    union_find(int N) { parent = vector<int> (N, -1); }

    int find(int u)
    {
        if (parent[u] < 0) return u;

        int v = find(parent[u]);
        parent[u] = v;

        return v;
    }

    void merge(int u, int v)
    {
        u = find(u), v = find(v);

        if (u == v) return;

        if (parent[u] > parent[v]) swap(u, v);

        parent[u] += parent[v];
        parent[v] = u;
    }

    int count()
    {
        int cnt = 0;

        for (vector<int>::iterator iter = parent.begin(); iter != parent.end(); iter++)
            if ((*iter) < 0)
                cnt += 1;
        
        return cnt;
    }
};

const int MAX = 3e3 + 1;

struct circle
{
    int x, y;
    double r;
};

int N;
circle c[MAX];

double get_distance(circle a, circle b);
bool is_connected(circle a, circle b);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T; cin >> T;

    while (T--)
    {
        cin >> N;

        for (int i = 0; i < N; i++)
            cin >> c[i].x >> c[i].y >> c[i].r;
        
        union_find *g = new union_find(N);

        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++)
                if (is_connected(c[i], c[j]))
                    g->merge(i, j);
        
        cout << g->count() << "\n";
    }

    return 0;
}

double get_distance(circle a, circle b)
{
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

bool is_connected(circle a, circle b)
{
    double coverage = a.r + b.r;

    if (get_distance(a, b) <= coverage)
        return true;
    
    return false;
}
