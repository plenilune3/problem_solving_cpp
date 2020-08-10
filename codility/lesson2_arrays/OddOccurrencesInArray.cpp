#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A);

int main(int argc, char const *argv[])
{
    int arr[] = { 9, 3, 9, 3, 9, 7, 9 };
    vector<int> test_case;
    test_case.assign(arr, arr + 7);

    cout << solution(test_case) << "\n";

    return 0;
}

int solution(vector<int> &A) {
    int answer = 0;
    
    for (vector<int>::iterator iter = A.begin(); iter != A.end(); iter++)
        answer ^= (*iter);
    
    return answer;
}
