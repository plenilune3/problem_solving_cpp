#include <iostream>
#include <vector>

using namespace std;

int M;
vector<int> dp;

string find_(int k, int target, int left, int right);

int main(int argc, char const *argv[])
{
    cin >> M;

    dp.push_back(7);
    dp.push_back(5);

    int k = 2;

    while (true)
    {
        if (dp[k - 1] > M - 1) break;

        dp.push_back(dp[k - 1] + 1 + dp[k - 2]);
        k += 1;
    }

    cout << find_(k - 1, M - 1, 0, dp[k - 1]);

    return 0;
}

string find_(int k, int target, int left, int right)
{
    if (k == 0)
    {
        string s = "Gimossi";

        return string(1, s[target - left]);
    }

    if (k == 1)
    {
        string s = "Messi";

        return string(1, s[target - left]);
    }

    int l = left + dp[k - 1], r = right - dp[k - 2];

    if (target == l)
        return "Messi Messi Gimossi";

    if (target < l)
        return find_(k - 1, target, left, l);
    else
        return find_(k - 2, target, r, right);
}
