#include <iostream>

using namespace std;

const int MAX = 101;

int N, A[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    int answer = 0;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    for (int i = N - 1; i >= 1; i--)
    {
        if (A[i] > A[i - 1]) continue;

        int diff = A[i - 1] - A[i];

        answer += diff + 1;

        A[i - 1] -= diff + 1;
    }

    cout << answer << "\n";

    return 0;
}
