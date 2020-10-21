#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;

    int idx = 0, title_num = 665;

    while (idx != N)
    {
        int temp = title_num++;
        bool possible = false;

        while (temp)
        {
            if (temp % 1000 == 666)
            {
                possible = true;
                break;
            }

            temp /= 10;
        }

        if (possible) idx++;
    }

    cout << title_num - 1 << "\n";
    
    return 0;
}