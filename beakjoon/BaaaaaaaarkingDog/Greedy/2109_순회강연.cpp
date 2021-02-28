#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 1e4 + 1;

struct lecture
{
    int d, p;

    lecture() : d(0), p(0) {};

    bool operator<(const lecture l) const
    {
        if (d != l.d) return d > l.d;
        else return p > l.p;
    }
};

int N, K;
lecture L[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> L[i].p >> L[i].d;
        K = max(K, L[i].d);
    }

    sort(&L[0], &L[0] + N);

    long long answer = 0;
    int index = 0;
    priority_queue<int> pq;

    for (int k = K; k >= 1; k--)
    {
        while (index < N && L[index].d == k)
            pq.push(L[index++].p);
        
        if (!pq.empty())
        {
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer << "\n";

    return 0;
}