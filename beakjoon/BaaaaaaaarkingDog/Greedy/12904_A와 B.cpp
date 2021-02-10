#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    string S, T; cin >> S >> T;

    bool possible = true;
    int length_S = (int) S.length(), length_T = (int) T.length();

    while (true)
    {
        if (length_S > length_T)
        {
            possible = false;
            break;
        }

        if (S == T) break;

        if (T[length_T - 1] == 'A')
        {
            T.erase(T.end() - 1);
            length_T -= 1;
        }
        else if (T[length_T - 1] == 'B')
        {
            T.erase(T.end() - 1);
            length_T -= 1;
            reverse(T.begin(), T.end());
        }
    }

    cout << possible << "\n";

    return 0;
}

