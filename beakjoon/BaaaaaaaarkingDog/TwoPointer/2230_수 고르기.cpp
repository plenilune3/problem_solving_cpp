#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX = 100001;

int N;
long long M, seq[MAX];

long long get_diff(long long a, long long b);
long long get_min_diff();

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> seq[i];
    
    sort(&seq[0], &seq[0] + N);

    long long answer = get_min_diff();

    cout << answer << "\n";

    return 0;
}

long long get_diff(long long a, long long b)
{
    return a >= b ? a - b : b - a;
}

long long get_min_diff()
{
    int left = 0, right = 0;
    long long  min_diff = LONG_LONG_MAX;

    while (true)
    {
        long long diff = get_diff(seq[left], seq[right]);

        if (diff >= M)
        {
            if (diff < min_diff)
                min_diff = diff;
            
            // M이 0일 때 left와 right가 서로 계속 증가하여 N을 초과할 수 있다.
            if (left < N - 1)
                left++;
            else
                break;
        }
        else if (right == N - 1)
            break;
        else
            right++;
    }

    return min_diff;
}
