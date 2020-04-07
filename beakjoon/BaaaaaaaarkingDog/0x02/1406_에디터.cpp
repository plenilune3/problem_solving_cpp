#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string initial_string;
    cin >> initial_string;

    list<char> buffer;
    for (int i = 0; i < initial_string.size(); i++)
        buffer.push_back(initial_string[i]);
    
    int N;
    cin >> N;

    list<char>::iterator cursor = buffer.end();

    for (int i = 0; i < N; i++)
    {
        char instruction;
        cin >> instruction;
        if (instruction == 'P')
        {
            char operand;
            cin >> operand;
            buffer.insert(cursor, operand);
        }
        else if (instruction == 'L')
        {
            if (cursor != buffer.begin())
                cursor--;
        }
        else if (instruction == 'D')
        {
            if (cursor != buffer.end())
                cursor++;
        }
        else if (instruction == 'B')
        {
            if (cursor != buffer.begin())
            {
                cursor--;
                cursor = buffer.erase(cursor);
            }
        }
    }

    for (list<char>::iterator i = buffer.begin(); i != buffer.end(); i++)
        cout << *i;
    
    return 0;
}
