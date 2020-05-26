#include <iostream>

using namespace std;

const int MAX = 100001;

int N, answer;
int S[MAX];
bool visited[2000001];

void dfs(int depth, int result)
{
    visited[result] = true;

    if (depth == N)
        return;

    dfs(depth + 1, result + S[depth]);
    dfs(depth + 1, result);
}

int main(int argc, char const *argv[])
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> S[i];
    
    dfs(0, 0);

    for (int i = 1; i <= 2000000; i++)
        if (visited[i] == false)
        {
            answer = i;
            break;
        }
    
    cout << answer << "\n";

    return 0;
}
