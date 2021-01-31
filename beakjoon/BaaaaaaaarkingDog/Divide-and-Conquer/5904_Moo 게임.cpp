#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e9 + 1;

int N;
char answer;
vector<int> dp;

void find_(int target, int k, int left, int right);

int main(int argc, char const *argv[])
{
    cin >> N;

    dp.push_back(3);
    int k = 1;

    while (true)
    {
        if (dp[k - 1] > (N - 1)) break;

        dp.push_back(2 * dp[k - 1] + (3 + k));
        k += 1;
    }

    find_(N - 1, k - 1, 0, dp[k - 1]);

    cout << answer << "\n";

    return 0;
}

void find_(int target, int k, int left, int right)
{
    if (k == 0)
    {
        answer = target == left ? 'm' : 'o';
        return;
    }

    int l = left + dp[k - 1], r = right - dp[k - 1];

    if (target >= l && target < r)
    {
        answer = target == l ? 'm' : 'o';
        return;
    }

    if (target < l)
        find_(target, k - 1, left, l);
    else if (target >= r)
        find_(target, k - 1, r, right);
}
