#include <iostream>
#include <stack>

using namespace std;

const int MAX = 1e5 + 2;

int N, A[MAX], answer;
stack<int> s;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    for (int i = 0; i <= N; i++)
    {
        while (!s.empty() && A[s.top()] > A[i])
        {
            int height = A[s.top()];
            s.pop();

            int width = 0;

            if (s.empty())
                width = i;
            else
                width = i - 1 - s.top();
            
            answer = max(answer, height * width);
        }

        s.push(i);
    }

    cout << answer << "\n";
    
    return 0;
}
