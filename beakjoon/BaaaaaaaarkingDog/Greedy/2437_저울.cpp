#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e3 + 1;

int N, A[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    sort(&A[0], &A[0] + N);
    
    int sum_ = 0;

    for (int i = 0; i < N; i++)
    {
        if (A[i] > sum_ + 1)
            break;
        
        sum_ += A[i];
    }

    cout << sum_ + 1 << "\n";

    return 0;
}
