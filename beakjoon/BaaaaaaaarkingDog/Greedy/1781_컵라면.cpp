#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 2e5 + 1;

struct problem
{
    int D, R;

    problem() : D(0), R(0) {};

    bool operator< (const problem &p) const
    {
        if (D != p.D) return D < p.D;
        else return R < p.R;
    }
};

int N, K;
problem problems[MAX];

bool compare(const problem &a, const problem &b);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> problems[i].D >> problems[i].R;
        K = max(K, problems[i].D);
    }

    sort(&problems[0], &problems[0] + N, compare);

    long long answer = 0;
    int index = 0;
    priority_queue<int> pq;

    for (int k = K; k >= 1; k--)
    {
        while (index < N && problems[index].D == k)
            pq.push(problems[index++].R);
        
        if (!pq.empty())
        {
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer << "\n";

    return 0;
}

bool compare(const problem &a, const problem &b)
{
    if (a.D != b.D) return a.D > b.D;
    else return a.R > b.R;
}
