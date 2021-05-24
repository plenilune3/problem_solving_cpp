#include <iostream>

using namespace std;

const int MAX = 27;

char P[MAX], I[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (cin >> P >> I)
    {
        cout << P << "\n";
        cout << I << "\n";
    }
    return 0;
}
