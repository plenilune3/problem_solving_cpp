#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; ;i++)
    {
        stack<char> s;
        string str;
        cin >> str;

        if (str[0] == '-')
            break;
        else
        {
            int length = str.length();
            int count = 0;

            for (int j = 0; j < length; j++)
            {
                if (str[j] == '{')
                {
                    s.push('{');
                }
                else
                {
                    if (s.empty())
                    {
                        count += 1;
                        s.push('{');
                    }
                    else
                    {
                        s.pop();
                    }
                }
            }

            count += s.size() / 2;
            cout << i << ". " << count << "\n";
        }
    }

    return 0;
}
