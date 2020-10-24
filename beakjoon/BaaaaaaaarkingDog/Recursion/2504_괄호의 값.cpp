#include <iostream>
#include <stack>

using namespace std;

const int MAX = 31;

string bracket;
int visited[MAX];

int calcuate_(int left, int right);

int main(int argc, char const *argv[])
{
    stack<int> s;
    bool possible = true;

    cin >> bracket;

    int length = (int) bracket.size();

    for (int i = 0; i < length; i++)
    {
        if (bracket[i] == '(' || bracket[i] == '[')
            s.push(i);
        else if (s.empty())
        {
            possible = false;
            break;
        }
        
        if ((bracket[i] == ')' && bracket[s.top()] == '(') || (bracket[i] == ']' && bracket[s.top()] == '['))
        {
            visited[s.top()] = i;
            visited[i] = s.top();
            s.pop();
        }
    }

    if (!s.empty() || possible == false)
        cout << 0 << "\n";
    else
        cout << calcuate_(0, length) << "\n";

    return 0;
}

int calcuate_(int left, int right)
{
    if (left == right)
        return 1;

    int result = 0;

    for (int i = left; i < right; i++)
    {
        if (bracket[i] == '(')
        {
            result += 2 * calcuate_(i + 1, visited[i]);
            i = visited[i];
        }
        else if (bracket[i] == '[')
        {
            result += 3 * calcuate_(i + 1, visited[i]);
            i = visited[i];
        }
    }

    return result;
}


