#include <cstdio>
#include <algorithm>
#include <deque>
#include <queue>

using namespace std;

const int MAX = 100002;

int bfs(int N, int K)
{
    int visited[MAX];
    fill_n(&visited[0], MAX, 0);
    deque<int> dq;
    visited[N] = 1;
    dq.push_back(N);

    if (N >= K)
        return N - K;

    while (!dq.empty())
    {
        int c = dq.front();
        dq.pop_front();

        if (c == K)
            break;
        
        if (c * 2 <= K + 1 && visited[c * 2] == 0)
        {
            visited[c*2] = visited[c];
            dq.push_front(c*2);
        }
        if (c - 1 >= 0 && visited[c - 1] == 0)
        {
            visited[c-1] = visited[c] + 1;
            dq.push_back(c-1);
        }
        if (c + 1 <= K + 1 && visited[c + 1] == 0)
        {
            visited[c+1] = visited[c] + 1;
            dq.push_back(c+1);
        }
    }

    return visited[K] - 1;
}

// int bfs(int N, int K)
// {
//     int visited[MAX];
//     fill_n(&visited[0], MAX, 0);
//     queue<int> q;
//     visited[N] = 1;
//     q.push(N);

//     if (N >= K)
//         return N - K;

//     while(!q.empty())
//     {
//         int c = q.front();
//         q.pop();

//         if (c == K)
//             break;

//         int t = c * 2;
//         while (t <= K + 1 && t != 0)
//         {
//             if (visited[t] == 0)
//             {
//                 visited[t] = visited[c];
//                 q.push(t);
//             }
//             t = t * 2;
//         }
        
//         if (c - 1 >= 0 && visited[c-1] == 0)
//         {
//             visited[c-1] = visited[c] + 1;
//             q.push(c-1);
//         }
        
//         if (c + 1 <= K + 1 && visited[c+1] == 0)
//         {
//             visited[c+1] = visited[c] + 1;
//             q.push(c+1);
//         }
//     }

//     return visited[K] - 1;
// }

int main(int argc, char const *argv[])
{
    int N, K;
    scanf("%d %d", &N, &K);

    int answer = bfs(N, K);
    printf("%d\n", answer);

    return 0;
}
