#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 2001;

int N;
long long A[MAX];

long long calculate_good(int N, long long A[MAX]);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    sort(&A[0], &A[0] + N);

    int answer = calculate_good(N, A);

    cout << answer << "\n";

    return 0;
}

long long calculate_good(int N, long long A[MAX])
{
    long long result = 0;

    for (int i = 0; i < N; i++)
    {
        int left = 0, right = N - 1;
        bool temp = false;

        while (left < right)
        {
            if (left == i)
                left += 1;
            else if (right == i)
                right -= 1;
            else
            {
                long long sum = A[left] + A[right];

                if (sum == A[i])
                {
                    temp = true;
                    break;
                }
                else if (sum > A[i])
                    right -= 1;
                else
                    left += 1;
            }
        }

        if (temp)
            result += 1;
    }

    return result;
}
