#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e5 + 1;

int N, A[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    long long answer = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    sort(&A[0], &A[0] + N, greater<int>());

    for (int i = 0; i < N; i++)
    {
        long long temp = A[i] - i;
        answer += temp >= 0 ? temp : 0;
    }

    cout << answer << "\n";
    
    return 0;
}
