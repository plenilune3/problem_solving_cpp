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
    int N = A.size();
    int answer = 1;
    
    if (N == 0)
        return 0;
    
    sort(A.begin(), A.end());
    
    for (int i = 1; i < N; i++)
    {
        if (A[i - 1] != A[i])
            answer += 1;
    }
    
    return answer;
}