#include <iostream>
#include <bitset>

using namespace std;

int N, K;
bitset<32> A;

int main(int argc, char const *argv[])
{
    cin >> N >> K;

    int answer = 0;

    A = N;
    while (A.count() > K)
    {
        answer += 1;
        N += 1;
        A = N;
    }

    cout << answer << "\n";

    return 0;
}
