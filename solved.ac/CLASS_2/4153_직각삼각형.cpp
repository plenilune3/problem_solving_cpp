#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int side[3];

    while (true)
    {
        for (int i = 0; i < 3; i++)
            cin >> side[i];
        
        if ((side[0] == 0) && (side[1] == 0) && (side[2] == 0))
            break;
        
        sort(side, side + 3);

        if (((side[0] * side[0]) + (side[1] * side[1])) == (side[2] * side[2]))
            cout << "right" << "\n";
        else
            cout << "wrong" << "\n";
    }

    return 0;
}
