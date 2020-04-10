#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<char> s;
    int answer = 0;
    string str;
    cin >> str;

    bool possible = true;
    int temp = 1;
    int length = str.length();

    for (int i = 0; i < length; i++)
    {
        if (str[i] == '(')
        {
            temp *= 2;
            s.push(str[i]);
        }
        else if (str[i] == '[')
        {
            temp *= 3;
            s.push(str[i]);
        }
        else if (str[i] == ')')
        {
            if (s.empty() || s.top() != '(')
            {
                possible = false;
                break;
            }
            else
            {
                if (str[i - 1] == '(')
                    answer += temp;
                s.pop();
                temp /= 2;
            }
        }
        else if (str[i] == ']')
        {
            if (s.empty() || s.top() != '[')
            {
                possible = false;
                break;
            }
            else
            {
                if (str[i - 1] == '[')
                    answer += temp;
                s.pop();
                temp /= 3;
            }
        }
    }

    if (possible && s.empty())
        cout << answer << "\n";
    else
        cout << 0 << "\n";

    return 0;
}
