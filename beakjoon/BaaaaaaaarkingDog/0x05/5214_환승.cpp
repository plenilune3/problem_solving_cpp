#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 100000;
const int MAX_M = 1000;

int N, K, M;
int dist[MAX_N + MAX_M + 2];
vector< int > graph[MAX_N + MAX_M + 2];

int bfs(int startStation, int endStation)
{
    queue<int> q;
    dist[startStation] = 1;
    q.push(startStation);

    while(!q.empty())
    {
        int x = q.front(); q.pop();

        if (x == endStation)
            return dist[x];
        
        for (vector<int>::iterator i = graph[x].begin(); i != graph[x].end(); i++)
        {
            if (dist[(*i)] != 0)
                continue;
            
            dist[(*i)] = dist[x] + 1;
            q.push((*i));
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> N >> K >> M;

    for (int m = 1; m <= M; m++)
    {
        for (int k = 0; k < K; k++)
        {
            int e;
            cin >> e;

            graph[N + m].push_back(e);
            graph[e].push_back(N + m);
        }
    }

    int answer = bfs(1, N);
    answer == -1 ? cout << -1 << "\n" : cout << (answer / 2) + 1 << "\n";

    return 0;
}
