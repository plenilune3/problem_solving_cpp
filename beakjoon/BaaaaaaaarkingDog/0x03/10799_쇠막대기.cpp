#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    stack<char> s;
    string str;
    cin >> str;

    int length = str.length();
    int answer = 0;

    for (int i = 0; i < length; i++)
    {
        if (str[i] == '(')
            s.push(str[i]);
        else
        {
            s.pop();

            if (str[i-1] == '(')
                answer += s.size();
            else
                answer++;
        }
    }

    cout << answer << "\n";

    return 0;
}
