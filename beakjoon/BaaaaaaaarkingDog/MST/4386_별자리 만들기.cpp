#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class union_find
{
private:
    vector<int> parent;

public:
    union_find (int N)
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

        if (parent[x] > parent[y]) swap(x, y);

        parent[x] += parent[y];
        parent[y] = x;
    }
};

struct edge 
{
    int u, v; double w;

    bool operator< (const edge &e) const
    {
        return w < e.w;
    }
};

const int MAX = 100 * 100 + 1;

int N;
pair<double, double> cooridate[100];
edge e[MAX];

double get_distance(pair<double, double> a, pair<double, double> b);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cout.precision(2);
    cout << fixed;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> cooridate[i].first >> cooridate[i].second;
    
    int idx = 0;

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
        {
            e[idx].u = i, e[idx].v = j;
            e[idx++].w = get_distance(cooridate[i], cooridate[j]);
        }
    
    sort(e, e + idx);

    union_find g(N);
    int cnt = 0; double sum_weight = 0;

    for (int i = 0; i < idx; i++)
    {
        if (cnt == N - 1)
            break;

        if (g.find(e[i].u) != g.find(e[i].v))
        {
            cnt += 1;
            g.merge(e[i].u, e[i].v);
            sum_weight += e[i].w;
        }
    }

    cout << sum_weight << "\n";

    return 0;
}

double get_distance(pair<double, double> a, pair<double, double> b)
{
    return sqrt((b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second));
}