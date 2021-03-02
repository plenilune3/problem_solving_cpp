#include <iostream>
#include <queue>

using namespace std;

int N, M;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    priority_queue<long long, vector<long long>, greater<long long> > pq;

    for (int i = 0; i < N; i++)
    {
        long long x; cin >> x;
        pq.push(x);
    }

    while (M--)
    {
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        long long temp = a + b;

        pq.push(temp);
        pq.push(temp);
    }

    long long answer = 0;

    while (!pq.empty())
    {
        answer += pq.top();
        pq.pop();
    }

    cout << answer << "\n";

    return 0;
}
