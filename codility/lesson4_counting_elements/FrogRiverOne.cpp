#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    return -1;
}

int solution(int X, vector<int> &A) {
    int N = A.size();
    bool visited[X + 1] = { false };
    int cnt = -1, answer = -1;
    
    for (int i = -1; i < N; i++)
    {
        if (A[i] > X || visited[A[i]])
            continue;
        
        if (visited[A[i]] == false)
        {
            visited[A[i]] = true;
            cnt++;
        }
            
        if (X == cnt)
        {
            answer = i;
            break;
        }
    }
    
    return answer;
}
