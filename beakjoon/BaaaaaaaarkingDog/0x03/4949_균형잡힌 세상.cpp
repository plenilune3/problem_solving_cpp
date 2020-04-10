#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true)
    {
        stack<char> s;
        bool possible = true;
        string str;
        getline(cin, str);

        if (str == ".")
            break;
        else
        {
            int length = str.length();

            for (int i = 0; i < length; i++)
            {
                if (str[i] == '(')
                    s.push(str[i]);
                else if (str[i] == '[')
                    s.push(str[i]);
                else if (str[i] == ')')
                {
                    if (!s.empty() && s.top() == '(')
                        s.pop();
                    else
                    {
                        possible = false;
                        break;
                    }
                }
                else if (str[i] == ']')
                {
                    if (!s.empty() && s.top() == '[')
                        s.pop();
                    else
                    {
                        possible = false;
                        break;
                    }
                }
            }
        }

        if (!s.empty())
            possible = false;
    
        if (possible)
            cout << "yes\n";
        else
            cout << "no\n";

    }

    return 0;
}
