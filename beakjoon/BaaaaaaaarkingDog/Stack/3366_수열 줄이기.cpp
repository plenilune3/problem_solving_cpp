#include <iostream>
#include <stack>

using namespace std;

const int MAX = 1e6 + 1;

int N, L;
stack<long long> S;
long long A[MAX], answer;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    for (int i = 0; i < N; i++)
    {
        while (!S.empty() && S.top() < A[i])
        {
            S.pop();
            L -= 1;

            if (S.empty())
                answer += A[i];
            else
                answer += min(S.top(), A[i]);
        }

        S.push(A[i]);
        L += 1;
    }

    while (L >= 2)
    {
        S.pop();
        long long b = S.top();
        S.pop();

        answer += b;
        S.push(b);
        L -= 1;
    }

    cout << answer << "\n";

    return 0;
}
