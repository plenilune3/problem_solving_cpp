#include <iostream>

using namespace std;

const int max = 1e5;

int N, K;

int find_num();

int main(int argc, char const *argv[])
{
    cin >> N >> K;

    int answer = find_num();

    cout << answer << "\n";

    return 0;
}

int find_num()
{
    int left = 1, right = K;
    int answer = 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        long long count = 0;

        for (int i = 1; i <= N; i++)
            count += min(mid / i, N);
        
        if (count >= K)
        {
            answer = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }

    return answer;
}
