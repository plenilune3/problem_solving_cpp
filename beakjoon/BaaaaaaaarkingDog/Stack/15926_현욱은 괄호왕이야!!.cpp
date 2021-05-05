#include <iostream>
#include <stack>

using namespace std;

const int MAX = 2e5 + 10;

int N, answer;
char A[MAX];
stack<int> S;

int calculate_length(int left, int right);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int answer = 0;
    cin >> N >> A;

    S.push(-1);

    for (int i = 0; i < N; i++)
    {
        if (A[i] == '(')
            S.push(i);
        else
        {
            S.pop();

            if (!S.empty())
                answer = max(answer, i - S.top());
            else
                S.push(i);
        }
    }

    cout << answer << "\n";

    return 0;
}