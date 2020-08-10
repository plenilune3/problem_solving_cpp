#include <iostream>
#include <map>

using namespace std;

int D, P, maxNumber, answer = -1;
map< pair<int, int>, bool > visited;

void backtracking(int depth, int result);
bool isImpossible(int number, int depth);

int main(int argc, char const *argv[])
{
    cin >> D >> P;

    for (int i = 0; i < D; i++)
        maxNumber = maxNumber * 10 + 9;

    backtracking(0, 1);
    cout << answer << "\n";

    return 0;
}

void backtracking(int depth, int result)
{
    if (isImpossible(result, depth))
        return;
    
    visited[make_pair(result, depth)] = true;

    if (depth == P)
    {
        answer = max(answer, result);
        return;
    }

    for (int i = 2; i <= 9; i++)
    {
        backtracking(depth + 1, result * i);
    }
}

bool isImpossible(int number, int depth)
{
    return number > maxNumber || visited[make_pair(number, depth)];
}
