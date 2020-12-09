#include <iostream>
#include <queue>

using namespace std;

const int MAX = 3e5 + 1;

int N, K;
int A[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        string s; cin >> s;
        A[i] = (int) s.size();
    }

    long long answer = 0;
    queue<int> q[21];

    for (int i = 0; i < N; i++)
    {
        int length = A[i];

        while (!q[length].empty() && i - q[length].front() > K)
            q[length].pop();
        
        answer += q[length].size();
        q[length].push(i);
    }

    cout << answer << "\n";

    return 0;
}
