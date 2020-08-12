#include <iostream>

using namespace std;

int solution(int X, int Y, int D);

int main(int argc, char const *argv[])
{
    cout << solution(10, 85, 30) << "\n";
    return 0;
}

int solution(int X, int Y, int D) {
    
    int answer = 0;
    
    answer += (Y - X) / D;
    
    (Y - X) % D ? answer++ : answer;
    
    return answer;
}
