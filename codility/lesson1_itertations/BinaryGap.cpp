#include <iostream>
#include <algorithm>

using namespace std;

int solution(int N);

int main(int argc, char const *argv[])
{
    int test_case[3] = { 1041, 15, 32 };

    for (int i = 0; i < 3; i++)
        cout << solution(test_case[i]) << "\n";
    
    return 0;
}

int solution(int N)
{
    int answer = 0, count = 0, pivot = 0;
    
    while (N)
    {
        int remain = N % 2;
        N /= 2;
        
        if (remain)
        {
            if (pivot)
            {
                answer = max(answer, count);
                count = 0;
            }
            else
                pivot = 1;
        }
        else
            if (pivot)
                count++;
    }
    
    return answer;
}

