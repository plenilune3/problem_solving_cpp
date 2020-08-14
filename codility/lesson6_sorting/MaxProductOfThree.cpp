#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> &A);

int main(int argc, char const *argv[])
{
    return 0;
}

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    
    if (N == 3)
        return A[0] * A[1] * A[2];
        
    sort(A.begin(), A.end());
    
    return max(A[N - 1] * A[N - 2] * A[N - 3], A[N - 1] * A[0] * A[1]);
}