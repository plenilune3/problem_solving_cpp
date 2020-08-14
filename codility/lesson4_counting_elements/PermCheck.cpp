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
    
    for (vector<int>::iterator iter = A.begin(); iter != A.end(); iter++)
    {
        int num = (*iter);
        
        if (num > N)
            return 0;
        
        if (visited[num])
            return 0;
        
        visited[num] = true;
    }
    
    return 1;
}

