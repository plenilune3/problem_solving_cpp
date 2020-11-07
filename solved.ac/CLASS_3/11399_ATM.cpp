#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e4 + 2;

int N;
int T[MAX];

int calculate_();

int main(int argc, char const *argv[])
{
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> T[i];
    
    sort(&T[0], &T[0] + N);

    int answer = calculate_();

    cout << answer << "\n";

    return 0;
}

int calculate_()
{
    int result = 0;
    int P[MAX] = { 0 };

    for (int i = 1; i <= N; i++)
        P[i] = P[i - 1] + T[i - 1];
    
    for (int i = 1; i <= N; i++)
        result += P[i];
    
    return result;
}
