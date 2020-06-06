#include <iostream>
#include <set>
#include <queue>
#include <map>

using namespace std;

const int MAX = 3001;

int N;
map< int, set<int> > graph;
int visited[MAX];
int dist[MAX];

int dfs(int x, int p)
{
    if (visited[x])
        return x; 

    visited[x] = true;

    for (set<int>::iterator i = graph[x].begin(); i != graph[x].end(); i++)
    {
        int y = (*i);

        if (y == p) continue;
        
        int res = dfs(y, x);

        if (res == -2) return -2;
        
        if (res >= 0)
        {
            visited[x] = 2;
            if (res == x) return -2;
            else return res;
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    dfs(1, 0);

    queue<int> q;

    for (int i = 1; i <= N; i++)
    {
        if (visited[i] == 2)
        {
            dist[i] = 0;
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        for (set<int>::iterator i = graph[x].begin(); i != graph[x].end(); i++)
        {
            int y = (*i);
            if (visited[y] == 2) continue;
            visited[y] = 2;
            dist[y] = dist[x] + 1;
            q.push(y);
        }
    }

    for (int i = 1; i <= N; i++)
        cout << dist[i] << " ";
    cout << "\n";

    return 0;
}
