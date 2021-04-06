#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 2e5 + 1;

int N, A[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    sort(&A[0], &A[0] + N);

    cout << A[(N - 1) / 2] << "\n";

    return 0;
}
