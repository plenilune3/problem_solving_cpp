#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        bool valid = true;
        string vps;
        cin >> vps;

        stack<char> s;
        int length = vps.length();

        for (int j = 0; j < length; j++)
        {
            if (vps[j] == '(')
                s.push(vps[j]);
            else
            {
                if (s.empty())
                {
                    cout << "NO\n";
                    valid = false;
                    break;
                }
                else
                    s.pop();
            }
        }

        if (valid)
        {
            if (s.empty())
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}
