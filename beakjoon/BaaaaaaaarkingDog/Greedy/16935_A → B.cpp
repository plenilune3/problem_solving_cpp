#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int A, B; cin >> A >> B;

    int answer = 0;
    bool possible = true;

    while (true)
    {
        if (A > B) 
        {
            possible = false;
            break;
        }

        if (A == B) break;

        if (B % 10 == 1) B /= 10;
        else if (B % 2 == 0) B /= 2;
        else
        {
            possible = false;
            break;
        }

        answer += 1;
    }
    
    if (possible)
        cout << answer + 1 << "\n";
    else
        cout << -1 << "\n";
    
    return 0;
}

