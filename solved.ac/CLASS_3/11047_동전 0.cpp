#include <iostream>

using namespace std;

const int MAX = 11;

int N, K, answer;
int A[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    for (int i = N - 1; i >= 0; i--)
    {
        int q = K / A[i], r = K % A[i];

        answer += q;
        K = r;
    }

    cout << answer << "\n";

    return 0;
}
