#include <iostream>

using namespace std;

const int r = 31;
const int M = 1234567891;

int L;

long long hashing(string &s);

int main(int argc, char const *argv[])
{
    string s;

    cin >> L;
    cin >> s;

    cout << hashing(s) << "\n";

    return 0;
}

long long hashing(string &s)
{
    long long hash = 0, coefficient = 1;

    for (int i = 0; i < L; i++)
    {
        hash += (s[i] - 'a' + 1) * coefficient;
        hash %= M;
        coefficient *= 31;
        coefficient %= M;
    }

    return hash;
}
