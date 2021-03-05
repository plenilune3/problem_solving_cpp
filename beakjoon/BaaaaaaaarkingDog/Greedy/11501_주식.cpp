#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e6 + 1;

int N, A[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T; cin >> T;

    while (T--)
    {
        int max_stock = 0;
        long long answer = 0;

        cin >> N;

        for (int i = 0; i < N; i++)
            cin >> A[i];
        
        reverse(&A[0], &A[0] + N);

        for (int i = 0; i < N; i++)
        {
            if (A[i] > max_stock)
            {
                max_stock = A[i];
                continue;
            }

            answer += max_stock - A[i];
        }

        cout << answer << "\n";
    }

    return 0;
}
