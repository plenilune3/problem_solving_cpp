#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    string value_type;
    cin >> value_type;

    string value;
    getline(cin, value);
    stringstream ss(value);

    string str;
    while (ss >> str)
    {
        string n_value_type = value_type;

        for (int i = str.size() - 1; i >= 0; i--)
        {
            if (str[i] == ',' || str[i] == ';')
                continue;
                
            if (isalpha(str[i]))
                break;
            else if (str[i] == ']')
                n_value_type.push_back('[');
            else if (str[i] == '[')
                n_value_type.push_back(']');
            else
                n_value_type.push_back(str[i]);
        }

        cout << n_value_type << " ";

        for (int i = 0; i < str.size(); i++)
        {
            if (isalpha(str[i]))
                cout << str[i];
            else
             break;
        }

        cout << ";\n";
    }

    return 0;
}
