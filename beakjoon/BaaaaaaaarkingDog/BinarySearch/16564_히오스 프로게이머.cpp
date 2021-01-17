#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e6 + 1;

int N, X[MAX];
long long K;

long long calculate_level(long long K);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i++)
        cin >> X[i];
    
    sort(&X[0], &X[0] + N);

    long long answer = calculate_level(K);

    cout << answer << "\n";

    return 0;
}

long long calculate_level(long long K)
{
    long long left = X[0], right = X[N - 1] + K;
    long long result = 0;

    while (left <= right)
    {
        long long mid = (left + right) / 2;
        long long temp = 0;

        for (int i = 0; i < N; i++)
            if (mid > X[i]) temp += mid - X[i];
            else break;

        if (temp <= K)
        {
            result = max(result, mid);
            left = mid + 1;
        }
        else
            right = mid - 1;
    }

    return result;
}