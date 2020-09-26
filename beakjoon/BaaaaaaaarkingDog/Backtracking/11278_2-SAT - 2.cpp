#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 21;

int N, M;
bool is_finished = false;
vector<bool> v, answer;
pair<int, int> clause[100];

bool is_possible();
void backtracking(int depth);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> N >> M;

    for (int i = 0; i < M; i++)
        cin >> clause[i].first >> clause[i].second;
    
    backtracking(0);

    cout << is_finished << "\n";

    if (is_finished)
    {
        for (vector<bool>::iterator iter = answer.begin(); iter != answer.end(); iter++)
            cout << (*iter) << " "; 
        cout << "\n";
    }

    return 0;
}

bool is_possible()
{
    for (int i = 0; i < M; i++)
    {
        bool x = clause[i].first > 0 ? v[abs(clause[i].first) - 1] : !v[abs(clause[i].first) - 1];
        bool y = clause[i].second > 0 ? v[abs(clause[i].second) - 1] : !v[abs(clause[i].second) - 1];

        if ((x || y) == false)
            return false;
    }

    return true;
}

void backtracking(int depth)
{
    if (is_finished)
        return;

    if (depth == N)
    {
        if (is_possible())
        {
            is_finished = true;
            answer.assign(v.begin(), v.end());
        }

        return;
    }

    for (int i = 0; i <= 1; i++)
    {
        v.push_back(i);
        backtracking(depth + 1);
        v.pop_back();
    }
}