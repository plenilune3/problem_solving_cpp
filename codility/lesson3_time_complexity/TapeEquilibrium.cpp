#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int get_difference(int a, int b);
int solution(vector<int> &A);

int main(int argc, char const *argv[])
{
    return 0;
}


int get_difference(int a, int b) {
    return a > b ? a - b : b - a;
}

int solution(vector<int> &A) {
    int answer = INT_MAX;
    int sum = 0;
    
    for (vector<int>::iterator iter = A.begin(); iter != A.end(); iter++)
        sum += (*iter);
    
    int left = 0, right = sum;
    vector<int>::iterator iter = A.begin();
    
    while (iter != A.end() - 1)
    {
        left += (*iter);
        right -= (*iter);
        
        answer = min(answer, get_difference(left, right)); 
        iter++;
    }
    
    return answer;
}
