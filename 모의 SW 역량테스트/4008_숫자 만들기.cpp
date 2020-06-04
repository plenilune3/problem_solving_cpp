#include <iostream>
#include <climits>

using namespace std;

const int MAX = 12;

int N, nums[MAX];

int result_min, result_max;

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        result_max = INT_MIN, result_min = INT_MAX;

        cin >> N;

        int a, s, m, d;
        cin >> a >> s >> m >> d;

        for (int i = 0; i < N; i++)
            cin >> nums[i];

        dfs(1, nums[0], a, s, m, d);

        int answer = result_max - result_min;

        cout << "#" << t << " " << answer << "\n";
    }

    return 0;
}
