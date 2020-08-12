#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    return 0;
}

vector<int> solution(int N, vector<int> &A) {
    vector<int> counter(N, 0);
    int lastMaxCounter = 0, nowMaxCounter = 0;

    for (vector<int>::iterator iter = A.begin(); iter != A.end(); iter++)
    {
        int num (*iter);

        if (num >= 1 && num <= N)
        {
            counter[num - 1] = max(counter[num - 1], lastMaxCounter);
            counter[num - 1]++;
            nowMaxCounter = max(nowMaxCounter, counter[num - 1]);
        }
        else if (num == N + 1)
        {
            lastMaxCounter = max(lastMaxCounter, nowMaxCounter);
        }
    }
    
    for (int i = 0; i < N; i++)
        counter[i] = max(counter[i], lastMaxCounter);
    
    return counter;
}