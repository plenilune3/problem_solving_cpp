#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 3e5 + 1;

long long N;
int M, jewels[MAX];

long long calculate_jealousy(long long N);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
        cin >> jewels[i];
    
    sort(&jewels[0], &jewels[0] + M);

    int result = calculate_jealousy(N);
    cout << result << "\n";

    return 0;
}

long long calculate_jealousy(long long N)
{
    long long left = 1, right = jewels[M - 1];
    long long result = __LONG_LONG_MAX__;

    while (left <= right)
    {
        long long mid = (left + right) / 2;
        long long temp = 0;

        for (int i = 0; i < M; i++)
            temp += (jewels[i] % mid == 0) ? jewels[i] / mid : jewels[i] / mid + 1;
        
        if (temp <= N)
        {
            result = min(result, mid);
            right = mid - 1;
        }
        else
            left = mid + 1;
    }

    return result;
}