#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10;

int N, answer;
vector<int> energy;

void backtracing(int depth, vector<int> e, int result)
{
    if (depth == N - 2)
    {
        answer = max(answer, result);
        return;
    }

    for (vector<int>::iterator i = e.begin() + 1; i != e.end() - 1; i++)
    {
        int result_next = result + (*(i - 1)) * (*(i + 1));
        vector<int>::iterator iter;
        int temp = (*i);
        iter = e.erase(i);
        backtracing(depth + 1, e, result_next);
        e.insert(iter, temp);
    }
}

int main(int argc, char const *argv[])
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        energy.push_back(t);
    }

    backtracing(0, energy, 0);

    cout << answer << "\n";

    return 0;
}
