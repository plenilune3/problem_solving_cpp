#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAX = 1000;

struct student
{
    int dist, num;
};

bool operator<(student a, student b)
{
    return a.dist > b.dist;
}

int N, M, X;
vector<student> forward_adj[MAX + 1];
vector<student> reverse_adj[MAX + 1];

student make_student(int dist, int num);
vector<int> find_shortest_path(int s, vector<student> adj[MAX + 1]);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> X;

    while (M--)
    {
        int u, v, w;

        cin >> u >> v >> w;

        forward_adj[u].push_back(make_student(w, v));
        reverse_adj[v].push_back(make_student(w, u));
    }

    vector<int> forward_dist = find_shortest_path(X, forward_adj);
    vector<int> reverse_dist = find_shortest_path(X, reverse_adj);

    int answer = 0;

    for (int i = 1; i <= N; i++)
        if (answer < forward_dist[i] + reverse_dist[i])
            answer = forward_dist[i] + reverse_dist[i];
    
    cout << answer << "\n";

    return 0;
}

student make_student(int dist, int num)
{
    return { dist, num };
}

vector<int> find_shortest_path(int s, vector<student> adj[MAX + 1])
{
    vector<int> dist(N + 1, INT_MAX);
    priority_queue<student> pq;
    dist[s] = 0;
    pq.push(make_student(0, s));

    while (!pq.empty())
    {
        int d = pq.top().dist, n = pq.top().num;
        pq.pop();

        if (d > dist[n])
            continue;
        
        for (vector<student>::iterator iter = adj[n].begin(); iter != adj[n].end(); iter++)
        {
            int nd = (*iter).dist, nn = (*iter).num;

            if (d + nd < dist[nn])
            {
                dist[nn] = d + nd;
                pq.push(make_student(d + nd, nn));
            }
        }
    }

    return dist;
}