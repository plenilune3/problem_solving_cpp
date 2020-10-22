#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int N; cin >> N;

    int result = 1;
    int num = 1;
    int diff = 6;

    while (num < N)
    {
        num += diff;
        diff += 6;
        result += 1;
    }

    cout << result << "\n";

    return 0;
}
