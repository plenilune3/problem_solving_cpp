#include <iostream>

using namespace std;

const int MAX = 2e5 + 1;

int N, K, A[MAX], C[MAX];

int calculate_length(int N, int K, int A[MAX]);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> N >> K;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    int answer = calculate_length(N, K, A);

    cout << answer << "\n";
    
    return 0;
}

int calculate_length(int N, int K, int A[MAX])
{
    int result = 0, length = 0;
    int left = 0, right = 0;

    while (true)
    {
        if (C[A[right - 1]] > K)
        {
            C[A[left]] -= 1;
            left += 1;
            length -= 1;
        }
        else if (right == N)
            break;
        else
        {
            C[A[right]] += 1;
            right += 1;
            length += 1;
        }

        if (C[A[right - 1]] <= K)
            result = max(result, length);
    }

    return result;
}