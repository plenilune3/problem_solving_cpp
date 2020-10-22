#include <iostream>

using namespace std;

int A, B, V;

int main(int argc, char const *argv[])
{
    cin >> A >> B >> V;
    int C = A - B, D = V - B;

    if (D % C)
        cout << D / C + 1 << "\n";
    else
        cout << D / C << "\n";

    return 0;
}
