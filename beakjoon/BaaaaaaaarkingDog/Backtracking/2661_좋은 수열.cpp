#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int MAX = 80;

int N;
bool is_finished;
string answer;

bool is_possible(string s);
void backtracking(int depth, string result);
string tostring(int a);

int main(int argc, char const *argv[])
{
    cin >> N;

    backtracking(0, "");
    cout << answer << "\n";

    return 0;
}

bool is_possible(string s)
{
    int length = s.size();

    for (int i = 1; i <= length / 2; i++)
    {
        int index = 0;

        while (index + i + i <= length)
        {
            if (s.substr(index, i) == s.substr(index + i, i))
                return false;
            index += 1;
        }
    }

    return true;
}

string tostring(int a)
{
    stringstream ss;
    ss << a;
    return ss.str();
}

void backtracking(int depth, string result)
{
    if (is_finished)
        return;

    if (depth == N)
    {
        is_finished = true;
        answer = result;
        return;
    }

    for (int i = 1; i <= 3; i++)
    {
        string next_result = result + tostring(i);

        if (is_possible(next_result))
            backtracking(depth + 1, next_result);
    }
}
