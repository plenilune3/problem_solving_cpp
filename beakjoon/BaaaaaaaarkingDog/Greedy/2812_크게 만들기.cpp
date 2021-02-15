#include <iostream>
#include <queue>

using namespace std;

const int MAX = 5e5 + 1;

int N, K;
char A[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    cin >> A;

    deque<int> dq;

    for (int i = 0; i < N; i++)
    {
        int temp = A[i] - '0';

        while (K && !dq.empty() && dq.back() < temp)
        {
            dq.pop_back();
            K--;
        }

        dq.push_back(temp);
    }

    for (int i = 0; i < dq.size() - K; i++)
        cout << dq[i];
    cout << "\n";

    return 0;
}
