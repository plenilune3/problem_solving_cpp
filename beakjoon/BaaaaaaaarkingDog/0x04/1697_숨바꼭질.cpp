#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100001;

int bfs(int N, int K)
{
    int visited[MAX] = { 0 };
    queue<int> q;
    q.push(N);
    visited[N] = 1;

    if (N >= K)
    {
        return N - K;
    }

    while (!q.empty())
    {
        int t = q.front();
        q.pop();

        if (t == K)
        {
            break;
        }

        if (t - 1 >= 0 && visited[t-1] == 0)
        {
            q.push(t - 1);
            visited[t-1] = visited[t] + 1;
        }
        if (t + 1 <= K + 1 && visited[t+1] == 0)
        {
            q.push(t + 1);
            visited[t+1] = visited[t] + 1;
        }
        if (t * 2 <= K + 1 && visited[t*2] == 0)
        {
            q.push(t * 2);
            visited[t*2] = visited[t] + 1;
        }
    }

    return visited[K] - 1;

}

int main(int argc, char const *argv[])
{
    int N, K;
    cin >> N >> K;

    int answer = bfs(N, K);
    cout << answer << "\n";

    return 0;
}
