#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int N; cin >> N;

    bool possible = false;
    int num = 0;

    while (num != N)
    {
        int temp = num;
        int result = num;

        while (temp)
        {
            result += temp % 10;
            temp /= 10;
        }

        if (result == N)
        {
            possible = true;
            break;
        }
        
        num++;
    }

    if (possible)
        cout << num << "\n";
    else
        cout << 0 << "\n";

    return 0;
}
