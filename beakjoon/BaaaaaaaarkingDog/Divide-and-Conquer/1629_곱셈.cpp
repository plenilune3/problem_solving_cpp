#include <iostream>

using namespace std;

int A, B, C;

long long pow(int a, int b);

int main(int argc, char const *argv[])
{
    cin >> A >> B >> C;

    cout << pow(A, B) % C << "\n";

    return 0;
}

long long pow(int a, int b)
{
    if (b == 0)
        return 1;
    
    long long n = pow(a, b / 2) % C;
    long long temp = (n * n) % C;

    if (b % 2 == 0)
        return temp;
    else
        return (a * temp) % C;
}
