#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> A, int K);

int main(int argc, char const *argv[])
{
    return 0;
}

vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0
    int N = A.size();
    vector<int> answer(N, 0);
    
    for (int i = 0; i < N; i++)
        answer[(i + K) % N] = A[i];
    
    return answer;
}
