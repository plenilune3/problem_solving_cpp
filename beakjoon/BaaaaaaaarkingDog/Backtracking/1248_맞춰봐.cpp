#include <iostream>
#include <vector>

using namespace std;

const int MAX = 11;

int N;
bool is_finished;
char S[MAX][MAX];
vector<int> v;

void find_nums(int depth);
bool is_possible(int depth);

int main(int argc, char const *argv[])
{
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            cin >> S[i][j];
    
    find_nums(0);
    return 0;
}

bool is_possible(int depth)
{
    int sum = 0;

    for (int i = 0; i < depth; i++)
    {
        sum += v[i];
        if (sum > 0 && S[i][depth] != '+') return false;
        if (sum == 0 && S[i][depth] != '0') return false;
        if (sum < 0 && S[i][depth] != '-') return false;
    }

    return true;
}

void find_nums(int depth)
{
    if (is_finished)
        return;

    if (depth == N)
    {
        is_finished = true;

        for (int i = 0; i < N; i++)
            cout << v[i] << " ";
        cout << "\n";

        return;
    }

    for (int i = -10; i <= 10; i++)
    {
        v.push_back(i);

        if (is_possible(depth))
            find_nums(depth + 1);

        v.pop_back();
    }
}
