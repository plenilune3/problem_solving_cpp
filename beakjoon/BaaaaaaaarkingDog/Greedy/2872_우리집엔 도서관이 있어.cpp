#include <iostream>

using namespace std;

const int MAX = 3e5 + 1;

int N, A[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    int answer = 0;
    int max_num = N;

    for (int i = N - 1; i >= 0; i--)
        if (A[i] == max_num)
        {
            max_num -= 1;
        }
        else
            answer += 1;
    
    cout << answer << "\n";

    return 0;
}
