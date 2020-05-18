#include <iostream>
#include <stack>
#include <string>

using namespace std;


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T;
    cin >> T;

    while(T--)
    {
        int array[100000] = { 0 };
        int bracket[4096] = { 0 };
        stack<int> s;

        int array_length, code_length, input_length;
        cin >> array_length >> code_length >> input_length;

        string code, input;

        cin >> code;
        cin >> input;

        for (int i = 0; i < code_length; i++)
        {
            if (code[i] == '[')
                s.push(i);
            else if (code[i] ==']')
            {
                bracket[i] = s.top();
                bracket[s.top()] = i;
                s.pop();
            }
        }

        int p = 0, c = 0, cnt = 0, index_max = -1;
        for (int i = 0; i < code_length; i++)
        {
            if (code[i] == '-')
                array[p] = (array[p] + 255) % 256;
            else if (code[i] == '+')
                array[p] = (array[p] + 1) % 256;
            else if (code[i] == '<')
                p = (p - 1 + array_length) % array_length;
            else if (code[i] == '>')
                p = (p + 1) % array_length;
            else if (code[i] == '[' && array[p] == false)
                i = bracket[i];
            else if (code[i] == ']' && array[p])
            {
                index_max = max(index_max, i);
                i = bracket[i];
            }
            else if (code[i] == ',')
                array[p] = (c == input_length ? 255 : input[c++]);
            
            if(++cnt == 50000000)
            {
                cout << "Loops " << bracket[index_max] << " " << index_max << "\n";
                break;
            }
        }

        if (cnt < 50000000)
            cout << "Terminates\n";
    }

    return 0;
}
