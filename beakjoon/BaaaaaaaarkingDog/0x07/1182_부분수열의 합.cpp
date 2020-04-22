#include <iostream>

using namespace std;

const int MAX = 21;

int N, S, answer;
int nums[MAX];

void dfs(int depth, int ac)
{
    if (depth == N)
    {   
        if (ac == S)
            answer++;
        return;
    }

    dfs(depth + 1, ac + nums[depth]);
    dfs(depth + 1, ac);
}


int main(int argc, char const *argv[])
{
    cin >> N >> S;

    for (int i = 0; i < N; i++)
        cin >> nums[i];
    
    dfs(0, 0);

    if (S == 0 && answer > 0)
        answer--;

    cout << answer << "\n";

    return 0;
}
