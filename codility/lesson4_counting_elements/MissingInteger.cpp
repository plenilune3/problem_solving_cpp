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
    bool visited[N + 1] = { false };
    int answer = N + 1;
    
    for (vector<int>::iterator iter = A.begin(); iter != A.end(); iter++)
    {
        int num = (*iter);

        if (num >= 1 && num <= N)
            visited[num] = true;
    }
    
    for (int i = 1; i <= N; i++)
        if (!visited[i])
        {
            answer = i;
            break;
        }
        
    return answer;
}



