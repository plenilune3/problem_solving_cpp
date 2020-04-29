#include <iostream>
#include <climits>

using namespace std;

const int MAX = 12;

int nums[MAX];
int N;
int result_max = INT_MIN;
int result_min = INT_MAX;

void dfs(int depth, int result, int a, int s, int m, int d)
{
    if (depth == N)
    {
        result_max = max(result_max, result);
        result_min = min(result_min, result);
        return;
    }

    if (a)
        dfs(depth + 1, result + nums[depth], a - 1, s, m, d);
    if (s)
        dfs(depth + 1, result - nums[depth], a, s - 1, m, d);
    if (m)
        dfs(depth + 1, result * nums[depth], a, s, m - 1, d);
    if (d)
        dfs(depth + 1, result / nums[depth], a, s, m, d - 1);
}

int main(int argc, char const *argv[])
{
    int a, s, m, d;
    cin >> N;
    
    for (int i = 0; i < N; i++)
        cin >> nums[i];

    cin >> a >> s >> m >> d;

    dfs(1, nums[0], a, s, m, d);

    cout << result_max << "\n" << result_min << "\n";

    return 0;
}
