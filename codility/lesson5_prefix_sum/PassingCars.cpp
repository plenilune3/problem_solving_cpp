#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A);

int main(int argc, char const *argv[])
{
    return 0;
}

int solution(vector<int> &A) {
    int N = A.size();
    int prefix_sum[N + 1] = { 0 };
    
    for (int i = 1; i <= N; i++)
        prefix_sum[i] = prefix_sum[i - 1] + A[i - 1];
    
    int answer = 0;
    
    for (int i = 0; i < N; i++)
    {
        if (A[i])
            continue;
        
        answer += prefix_sum[N] - prefix_sum[i];
        
        if (answer > 10e8)
        {
            answer = -1;
            break;
        }
    }
    
    return answer;
}


