#include <iostream>

using namespace std;

const int MAX = 3e6 + 1;

int N, D, K, C;
int A[MAX], counter[3001];

int calculate(int N, int D, int K, int C, int A[MAX]);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> D >> K >> C;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    int answer = calculate(N, D, K, C, A);

    cout << answer << "\n";

    return 0;
}

int calculate(int N, int D, int K, int C, int A[MAX])
{
    int result = 0;
    int left = 0, right = 0, length = 0, temp = 0;

    while (true)
    {
        if (length >= K)
        {
            if (counter[A[left]] == 1)
                temp -= 1;

            counter[A[left]] -= 1;
            left += 1;
            length -= 1;
        }
        else if (right == (N + K))
            break;
        else
        {
            if (counter[A[right % N]] == 0)
                temp += 1;
            
            counter[A[right % N]] += 1;
            right += 1;
            length += 1;
        }

        if (counter[C] == 0)
            result = max(result, temp + 1);
        else
            result = max(result, temp);
    }

    return result;
}