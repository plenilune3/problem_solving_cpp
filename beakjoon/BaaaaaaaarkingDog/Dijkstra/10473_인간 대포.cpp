#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;

const int MAX = 103;

struct edge
{
    int v;
    double w;

    bool operator< (const edge &e) const
    {
        if (w != e.w) return w > e.w;
        else return v > e.v;
    }
};

int N;
pair<double, double> coordinate[MAX];
vector< vector<edge> > node(MAX);

void make_connect(int i, int j);
double get_distance(pair<double, double> a, pair<double, double> b);
edge make_edge(int v, double w);
double find_path(int src);

int main(int argc, char const *argv[])
{
    cout << fixed;
    cout.precision(6);

    cin >> coordinate[1].first >> coordinate[1].second;
    cin >> coordinate[2].first >> coordinate[2].second;
    cin >> N;

    for (int i = 3; i <= N + 2; i++)
        cin >> coordinate[i].first >> coordinate[i].second;
    
    for (int i = 1; i <= N + 2; i++)
        for (int j = i + 1; j <= N + 2; j++)
        {
            make_connect(i, j);
            make_connect(j, i);
        }
    
    double answer = find_path(1);

    cout << answer << "\n";

    return 0;
}

void make_connect(int i, int j)
{
    double distance = get_distance(coordinate[i], coordinate[j]);

    if (i == 1 || i == 2)
    {
        double w = distance / (double) 5;
        node[i].push_back(make_edge(j, w));
    }
    else
    {
        double w = min(2.0 + fabs(50.0 - distance) / 5.0, distance / 5.0);
        node[i].push_back(make_edge(j, w));
    }
}

double get_distance(pair<double, double> a, pair<double, double> b)
{
    return sqrt((b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second));
}

edge make_edge(int v, double w)
{
    edge e = { v, w };
    return e;
}

double find_path(int src)
{
    double dist[N + 3];
    fill_n(&dist[0], N + 3, INT_MAX);
    priority_queue<edge> pq;
    dist[src] = 0;
    pq.push(make_edge(src, 0));

    while (!pq.empty())
    {
        int v = pq.top().v; double w = pq.top().w;
        pq.pop();

        if (dist[v] < w)
            continue;

        for (vector<edge>::iterator iter = node[v].begin(); iter != node[v].end(); iter++)
        {
            int nv = (*iter).v; double nw = (*iter).w;

            if (dist[nv] > nw + w)
            {
                dist[nv] = nw + w;
                pq.push(make_edge(nv, nw + w));
            }
        }
    }

    return dist[2];
}
