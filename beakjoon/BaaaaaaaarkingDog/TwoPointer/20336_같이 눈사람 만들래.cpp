#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX = 601;

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

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 3; j < N; j++)
        {
            int elsa = A[i] + A[j];
            int left = i + 1, right = j - 1;

            while (left < right)
            {
                int anna = A[left] + A[right];
                int diff = elsa - anna;

                result = min(result, abs(diff));

                if (diff < 0)
                    right -= 1;
                else
                    left += 1;
            }
        }
    }

    return result;
}