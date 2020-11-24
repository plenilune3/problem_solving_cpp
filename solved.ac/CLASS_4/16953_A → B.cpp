#include <iostream>
#include <climits>

using namespace std;

int dfs(int depth, long long A, long long B);

int main(int argc, char const *argv[])
{
    int A, B;
    cin >> A >> B;

    int answer = dfs(0, A, B);

    if (answer != INT_MAX)
        cout << answer + 1 << "\n";
    else
        cout << -1 << "\n";

    return 0;
}

int dfs(int depth, long long A, long long B)
{
    if (A > B)
        return INT_MAX;

    if (A == B)
        return depth;
    
    int ret = min(dfs(depth + 1, A * 2, B), dfs(depth + 1, A * 10 + 1, B));

    return ret;
}
