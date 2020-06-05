#include <iostream>
#include <climits>

using namespace std;

int A, B, C, D, answer;
int month[13];

void dfs(int depth, int result)
{
    if (depth >= 13)
    {
        answer = min(answer, result);
        return;
    }

    dfs(depth + 1, result + month[depth] * A);
    dfs(depth + 1, result + B);
    dfs(depth + 3, result + C);
    dfs(13, result + D);
}

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        answer = INT_MAX;
        cin >> A >> B >> C >> D;

        for (int i = 1; i <= 12; i++)
            cin >> month[i];
        
        dfs(1, 0);
        
        cout << "#" << t << " " << answer << "\n";
    }

    return 0;
}
