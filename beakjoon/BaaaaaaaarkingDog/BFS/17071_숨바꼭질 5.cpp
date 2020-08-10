#include <cstdio>
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

int bfs(int N, int K, bool visited[][2])
{
    queue<position> q;
    visited[N][0] = true;
    q.push({N, K, 0});

    while(!q.empty())
    {
        position c = q.front();
        q.pop();

        if (visited[c.k][c.count % 2])
            return c.count;
        
        for (int i = 0; i < 3; i++)
        {
            int nn = (c.n + dx[i]) * dm[i];
            int nc = c.count + 1;
            int nk = (c.k + nc);

            if (nn < 0 || nn > MAX || nk > MAX)
                continue;
            
            if (visited[nn][nc % 2] == false)
            {
                visited[nn][nc % 2] = true;
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

    bool visited[MAX][2];
    fill_n(&visited[0][0], MAX*2, false);

    int answer = bfs(N, K, visited);
    printf("%d\n", answer);

    return 0;
}
