#include <iostream>

using namespace std;

const int MAX = 15;

int N, answer;
int T[MAX], P[MAX];

void dfs(int depth, int sum);

int main(int argc, char const *argv[])
{
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> T[i] >> P[i];
    
    dfs(0, 0);

    cout << answer << "\n";
    
    return 0;
}

void dfs(int depth, int sum)
{
    if (depth == N)
    {
        answer = max(answer, sum);
        return;
    }

    if (depth + T[depth] <= N)
        dfs(depth + T[depth], sum + P[depth]);

    dfs(depth + 1, sum);
}
