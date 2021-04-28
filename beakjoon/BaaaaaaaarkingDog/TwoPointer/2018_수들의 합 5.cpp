#include <iostream>

using namespace std;

int N;

int count_(int N);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    
    int answer = count_(N);

    cout << answer << "\n";

    return 0;
};

int count_(int N)
{
    int result = 0;
    int left = 1, right = 1, sum = 0;

    while (true)
    {
        if (sum >= N)
            sum -= left++;
        else if (right == N + 1)
            break;
        else
            sum += right++;
        
        if (sum == N)
            result += 1;
    }

    return result;
}
