#include <iostream>

using namespace std;

int solution(int A, int B, int K);

int main(int argc, char const *argv[])
{
    return 0;
}

int solution(int A, int B, int K)
{
    if (A == 0)
        return B / K + 1;
    else
        return (B / K + 1) - ((A - 1) / K + 1);
}
