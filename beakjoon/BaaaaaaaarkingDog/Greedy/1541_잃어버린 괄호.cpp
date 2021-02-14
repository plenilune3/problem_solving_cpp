#include <iostream>

using namespace std;

const int MAX = 55;

int answer;
string S;
bool m;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> S;

    string temp = "";

    for (string::iterator i = S.begin(); i != S.end(); i++)
    {
        if ((*i) == '+' || (*i) == '-')
        {
            if (m) answer -= stoi(temp);
            else answer += stoi(temp);

            temp.clear();

            if ((*i) == '-') m = true;

            continue;
        }

        temp += (*i);
    }

    if (m) answer -= stoi(temp);
    else answer += stoi(temp);

    cout << answer << "\n";

    return 0;
}
