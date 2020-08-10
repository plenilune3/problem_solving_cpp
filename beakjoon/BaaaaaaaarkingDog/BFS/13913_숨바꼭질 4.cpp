#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 100001;

struct answer
{
    int count;
    vector<int> v;
};

answer bfs(int N, int K)
{
    queue<int> q;
    int visited[MAX];
    int prev[MAX];
    fill_n(&visited[0], MAX, -1);
    fill_n(&prev[0], MAX, -1);
    visited[N] = 0;
    q.push(N);

    while (!q.empty())
    {
        int c = q.front();
        q.pop();

        if (c == K)
            break;

        if (c - 1 >= 0 && visited[c-1] == -1)
        {
            visited[c-1] = visited[c] + 1;
            prev[c-1] = c;
            q.push(c-1);
        }

        if (c + 1 <= K + 1 && visited[c+1] == -1)
        {
            visited[c+1] = visited[c] + 1;
            prev[c+1] = c;
            q.push(c+1);
        }

        if (c * 2 <= K + 1 && visited[c*2] == -1)
        {
            visited[c*2] = visited[c] + 1;
            prev[c*2] = c;
            q.push(c*2);
        }
    }

    vector<int> v;
    int t = K;

    while (t != -1)
    {
        v.push_back(t);
        t = prev[t];
    }

    return { visited[K], v };
}

int main(int argc, char const *argv[])
{
    int N, K;
    scanf("%d %d", &N, &K);

    answer a = bfs(N, K);
    
    printf("%d\n", a.count);
    
    int length = a.count + 1;
    for (int i = length - 1; i >= 0; i--)
    {
        printf("%d ", a.v[i]);
    }

    return 0;
}
