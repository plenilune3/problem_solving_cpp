#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 3e5 + 1;

int N, K, A[MAX], B[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    for (int i = 0; i < N - 1; i++)
        B[i] = A[i + 1]  - A[i];
    
    sort(&B[0], &B[0] + N - 1);

    int answer = 0;

    for (int i = 0; i < N - K; i++)
        answer += B[i];
    
    cout << answer << "\n";

    return 0;
}
