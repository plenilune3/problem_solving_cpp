#include <iostream>

using namespace std;

const int MAX = 13;

int N, X, Y, answer;
int seq[MAX * 2];
bool visited[MAX];

void backtracking(int depth);

int main(int argc, char const *argv[])
{
    cin >> N >> X >> Y;

    seq[X] = seq[Y] = Y - X - 1;
    visited[Y - X - 1] = true;

    backtracking(1);

    cout << answer << "\n";

    return 0;
}

void backtracking(int depth)
{
    if (depth == N * 2)
    {
        answer += 1;
        return;
    }

    if (seq[depth] != 0)
    {
        backtracking(depth + 1);
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        if (visited[i])
            continue;
        
        if (depth + i + 1 <= N * 2 && seq[depth + i + 1] == 0)
        {
            visited[i] = true;
            seq[depth] = seq[depth + i + 1] = i;
            backtracking(depth + 1);
            visited[i] = false;
            seq[depth] = seq[depth + i + 1] = 0;
        }
    }
}
