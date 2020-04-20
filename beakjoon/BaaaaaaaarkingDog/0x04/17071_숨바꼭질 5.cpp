#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 500001;

struct position
{
    int n;
    int k;
    int count;
};

int dx[] = {-1, 1, 0};
int dm[] = {1, 1, 2};
bool visited[2][MAX] = { false };

int bfs(int N, int K)
{
    queue<position> q;
    visited[0][N] = true;
    q.push({N, K, 0});

    while(!q.empty())
    {
        position c = q.front();
        q.pop();

        if (visited[c.count % 2][c.k])
            return c.count;
        
        for (int i = 0; i < 3; i++)
        {
            int nn = (c.n + dx[i]) * dm[i];
            int nc = c.count + 1;
            int nk = (c.k + nc);

            if (nn < 0 || nn > MAX || nk > MAX)
                continue;
            
            if (visited[nc % 2][nn] == false)
            {
                visited[nc % 2][nn] = true;
                q.push({nn, nk, nc});
            }
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    int N, K;
    scanf("%d %d", &N, &K);

    int answer = bfs(N, K);
    printf("%d\n", answer);

    return 0;
}
