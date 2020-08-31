#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX = 1e4;

int K, N;
int line[MAX];

long long find_max_length();

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> K >> N;

    for (int i = 0; i < K; i++)
        cin >> line[i];
    
    sort(&line[0], &line[0] + K);

    long long answer = find_max_length();

    cout << answer << "\n";

    return 0;
}

long long find_max_length()
{
    long long left = 0, right = INT_MAX;
    long long max_length = 0;

    while (left <= right)
    {
        long long mid = (left + right) / 2;
        long long count = 0;

        for (int i = 0; i < K; i++)
            count += line[i] / mid;
        
        if (count >= N)
        {
            max_length = max(max_length, mid);
            left = mid + 1;
        }
        else
            right = mid - 1;
    }

    return max_length;
}
