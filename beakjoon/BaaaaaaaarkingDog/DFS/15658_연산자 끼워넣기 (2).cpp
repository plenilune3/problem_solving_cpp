#include <iostream>
#include <climits>

using namespace std;

const int MAX = 11;

int N, A, S, M, D;
int nums[MAX];
int min_result = INT_MAX, max_result = INT_MIN;

void dfs(int depth, int result, int a, int s, int m, int d);

int main(int argc, char const *argv[])
{
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> nums[i];
    
    cin >> A >> S >> M >> D;

    dfs(1, nums[0], A, S, M, D);


    cout << max_result << "\n";
    cout << min_result << "\n";
    
    return 0;
}

void dfs(int depth, int result, int a, int s, int m, int d)
{
    if (depth == N)
    {
        min_result = min(min_result, result);
        max_result = max(max_result, result);
        return;
    }

    if (a) dfs(depth + 1, result + nums[depth], a - 1, s, m, d);
    if (s) dfs(depth + 1, result - nums[depth], a, s - 1, m, d);
    if (m) dfs(depth + 1, result * nums[depth], a, s, m - 1, d);
    if (d) dfs(depth + 1, result / nums[depth], a, s, m, d - 1);
}
