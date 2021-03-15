#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e4 + 1;

int N;
int A[MAX], B[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T; cin >> T;

    while (T--)
    {
        cin >> N;

        for (int i = 0; i < N; i++)
            cin >> A[i];
        
        sort(&A[0], &A[0] + N);

        int left = 0, right = N - 1;

        for (int i = 0; i < N; i++)
        {
            if (i % 2 == 0) B[left++] = A[i];
            else B[right--] = A[i];
        }

        int answer = abs(B[0] - B[N - 1]);

        for (int i = 0; i < N - 1; i++)
            answer = max(answer, abs(B[i] - B[i + 1]));
        
        cout << answer << "\n";
    }

    return 0;
}
