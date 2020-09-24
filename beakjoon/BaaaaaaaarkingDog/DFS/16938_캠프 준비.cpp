#include <iostream>
#include <climits>

using namespace std;

const int MAX = 15;

int N, L, R, X, answer;
int level[MAX];

void dfs(int depth, int min_level, int max_level, int sum_level);

int main(int argc, char const *argv[])
{
    cin >> N >> L >> R >> X;

    for (int i = 0; i < N; i++)
        cin >> level[i];
    
    dfs(0, INT_MAX, INT_MIN, 0);
    cout << answer << "\n";

    return 0;
}

void dfs(int depth, int min_level, int max_level, int sum_level)
{    
    if (depth == N)
    {
        if (sum_level != 0 && sum_level >= L && sum_level <= R && (max_level - min_level) >= X)
            answer += 1;
        return;
    }

    dfs(depth + 1, min(min_level, level[depth]), max(max_level, level[depth]), sum_level + level[depth]);
    dfs(depth + 1, min_level, max_level, sum_level);
}
