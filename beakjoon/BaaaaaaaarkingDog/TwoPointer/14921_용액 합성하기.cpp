#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

const int MAX = 1e5 + 1;

int N, A[MAX];

int calculate_diff(int N, int A[MAX]);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    sort(&A[0], &A[0] + N);

    int answer = calculate_diff(N, A);

    cout << answer << "\n";

    return 0;
}

int calculate_diff(int N, int A[MAX])
{
    int result = INT_MAX;
    int left = 0, right = N - 1;

    while (left < right)
    {
        int sum = A[left] + A[right];

        if (abs(sum) < abs(result))
            result = sum;

        if (sum < 0)
            left += 1;
        else
            right -= 1;
    }

    return result;
}
