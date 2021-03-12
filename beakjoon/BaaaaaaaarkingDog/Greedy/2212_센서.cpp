#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e4 + 1;

int N, K;
int A[MAX], B[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    sort(&A[0], &A[0] + N);

    for (int i = 0; i < N - 1; i++)
        B[i] = A[i + 1] - A[i];
    
    sort(&B[0], &B[0] + N - 1);

    long long answer = 0;

    for (int i = 0; i < (N - 1) - (K - 1); i++)
        answer += B[i];
    
    cout << answer << "\n";
    
    return 0;
}
