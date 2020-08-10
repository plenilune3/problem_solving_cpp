#include <iostream>
#include <queue>
#include <map>
#include <set>

using namespace std;

const int MAX = 100;

int N, M, A, B;
map<int, set<int> > graph;

int bfs(int a, int b)
{
    queue<int> q;
    int dist[MAX];
    fill_n(&dist[0], MAX, -1);
    dist[a] = 0;
    q.push(a);

    while (!q.empty())
    {
        int n = q.front();
        q.pop();

        if (n == b)
            return dist[n];

        for (set<int>::iterator iter = graph[n].begin(); iter != graph[n].end(); iter++)
        {
            if (dist[(*iter)] != -1)
                continue;
            
            dist[(*iter)] = dist[n] + 1;
            q.push((*iter));
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    cin >> N;
    cin >> A >> B;
    cin >> M;

    for (int i = 1; i <= M; i++)
    {
        int S, T;
        cin >> S >> T;
        graph[S].insert(T);
        graph[T].insert(S);
    }

    cout << bfs(A, B) << "\n";

    return 0;
}
