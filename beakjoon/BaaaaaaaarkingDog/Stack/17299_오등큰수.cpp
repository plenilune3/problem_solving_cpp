#include <iostream>
#include <stack>

using namespace std;

const int MAX = 1e6 + 1;

int N, A[MAX], B[MAX], C[MAX];
stack<int> s;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        C[A[i]] += 1;
    }
    
    for (int i = N - 1; i >= 0; i--)
    {
        while (!s.empty() && C[s.top()] <= C[A[i]])
            s.pop();
        
        if (s.empty())
            B[i] = -1;
        else
            B[i] = s.top();
        
        s.push(A[i]);
    }

    for (int i = 0; i < N; i++)
        cout << B[i] << " ";
    cout << "\n";

    return 0;
}
