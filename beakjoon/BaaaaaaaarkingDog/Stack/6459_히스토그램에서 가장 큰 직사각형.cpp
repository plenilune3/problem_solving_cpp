#include <iostream>
#include <stack>

using namespace std;

const int MAX = 1e5 + 2;

int N, A[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (true)
    {
        stack<int> s;
        long long answer = 0;

        cin >> N;

        if (N == 0)
            break;
        
        fill_n(&A[0], MAX, 0);

        for (int i = 0; i < N; i++)
            cin >> A[i];
        
        for (int i = 0; i <= N; i++)
        {
            while (!s.empty() && A[s.top()] > A[i])
            {
                long long height = A[s.top()];
                s.pop();

                long long width = 0;

                if (s.empty())
                    width = i;
                else
                    width = i - 1 - s.top();
                
                answer = max(answer, height * width);
            }

            s.push(i);
        }

        cout << answer << "\n";
    }

    return 0;
}
