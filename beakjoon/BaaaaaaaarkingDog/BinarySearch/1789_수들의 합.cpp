#include <iostream>

using namespace std;

long long S;

long long calculate_sum(long long n);
long long find_N(long long S);

int main(int argc, char const *argv[])
{
    cin >> S;

    cout << find_N(S) << "\n";

    return 0;
}

long long find_N(long long S)
{
    long long left = 1, right = S;
    long long answer = 0;

    while (left <= right)
    {
        long long mid = (left + right) / 2;

        long long sum = calculate_sum(mid);

        if (sum <= S)
        {
            left = mid + 1;
            answer = max(answer, mid);
        }
        else
            right = mid - 1;
    }

    return answer;
}

long long calculate_sum(long long n)
{
    return (n * (n + 1)) / 2;
}
