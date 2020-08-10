#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100001;

int A, B, N, M;
int dist[MAX];

int bfs()
{
    int dx[] = { -1, -A, -B, B, A, 1};
    int dy[] = { A, B };

    queue<int> q;
    dist[N] = 1;
    q.push(N);

    while(!q.empty())
    {
        int x = q.front(); q.pop();
        if (x == M)
            return dist[x];
        
        for (int i = 0; i < 6; i++)
        {
            int nx = x + dx[i];

            if (nx < 0 || nx > 100000 || dist[nx] != 0)
                continue;
            
            dist[nx] = dist[x] + 1;
            q.push(nx);
        }

        for (int i = 0; i < 2; i++)
        {
            int nx = x * dy[i];

            if (nx < 0 || nx > 100000 || dist[nx] != 0)
                continue;
            
            dist[nx] = dist[x] + 1;
            q.push(nx);
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    cin >> A >> B >> N >> M;
    cout << bfs() - 1 << "\n";

    return 0;
}
