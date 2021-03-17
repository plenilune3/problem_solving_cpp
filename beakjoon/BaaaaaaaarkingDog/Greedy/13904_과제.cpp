#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 1e3 + 1;

struct assignment
{
    int d, w;

    bool operator< (const assignment &a) const
    {
        if (d != a.d) return d > a.d;
        else return w > a.w;
    }
};

int N, K;
assignment A[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i].d >> A[i].w;
        K = max(K, A[i].d);
    }
    
    sort(&A[0], &A[0] + N);

    int answer = 0, index = 0;
    priority_queue<int> pq;

    for (int k = K; k >= 1; k--)
    {
        while (index < N && A[index].d == k)
            pq.push(A[index++].w);

        if (!pq.empty())
        {
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer << "\n";

    return 0;
}
