#include <iostream>
#include <climits>

using namespace std;

const int MAX = 11;

int N, A, S, M, D, min_result = INT_MAX, max_result = INT_MIN;
int nums[MAX];

void dfs(int depth, int result, int A, int S, int M, int D);

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

void dfs(int depth, int result, int A, int S, int M, int D)
{
    if (depth == N)
    {
        min_result = min(min_result, result);
        max_result = max(max_result, result);
        return;
    }

    if (A) dfs(depth + 1, result + nums[depth], A - 1, S, M, D);
    if (S) dfs(depth + 1, result - nums[depth], A, S - 1, M, D);
    if (M) dfs(depth + 1, result * nums[depth], A, S, M - 1, D);
    if (D) dfs(depth + 1, result / nums[depth], A, S, M, D - 1);
}
