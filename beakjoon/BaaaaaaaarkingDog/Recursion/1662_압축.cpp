#include <iostream>
#include <stack>

using namespace std;

const int MAX = 51;

string str;
string answer;
int bracket[MAX];

int decompress(int left, int right);

int main(int argc, char const *argv[])
{
    cin >> str;
    
    int length = (int) str.size();
    
    stack<int> s;

    for (int i = 0; i < length; i++)
    {
        if (str[i] == '(')
            s.push(i);
        else if (str[i] == ')')
        {
            bracket[s.top()] = i;
            bracket[i] = s.top();
            s.pop();
        }
    }

    cout << decompress(0, length) << "\n";

    return 0;
}

int decompress(int left, int right)
{
    int ret = 0;
    
    for (int i = left; i < right; i++)
    {
        if (str[i] == '(')
        {
            ret -= 1;
            int k = str[i - 1] - '0';

            ret += k * decompress(i + 1, bracket[i]);
            
            i = bracket[i];
            continue;
        }

        ret += 1;
    }

    return ret;
}
