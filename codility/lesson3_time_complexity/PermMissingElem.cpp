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
    int answer = N + 1;
    
    for (int i = 0; i < N; i++)
    {
        answer += (i + 1);
        answer -= A[i];
    }
    
    return answer;
}
