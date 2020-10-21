#include <iostream>

using namespace std;

bool is_palindrome(string &str);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (true)
    {
        string str;
        cin >> str;

        if (str == "0")
            break;
        
        if (is_palindrome(str))
            cout << "yes" << "\n";
        else
            cout << "no" << "\n";
    }
    
    return 0;
}

bool is_palindrome(string &str)
{
    int left = 0, right = str.size() - 1;

    while (left < right)
    {
        if (str[left++] != str[right--])
            return false;
    }

    return true;
}