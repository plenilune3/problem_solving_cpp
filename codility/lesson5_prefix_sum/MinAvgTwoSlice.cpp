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
    
    double min_average = 10000;
    int answer = 0;
    
    for (int i = 0; i < N - 1; i++)
    {
        double two_element_average = (prefix_sum[i + 2] - prefix_sum[i]) / (double) 2;
        
        if (min_average > two_element_average)
        {
            min_average = two_element_average;
            answer = i;
        }
        
        if (i + 3 <= N)
        {
            double three_element_average = (prefix_sum[i + 3] - prefix_sum[i]) / (double) 3;
            
            if (min_average > three_element_average)
            {
                min_average = three_element_average;
                answer = i;
            }
        }
    }
        
    return answer;
}