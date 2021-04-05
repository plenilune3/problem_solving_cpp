#include <iostream>
#include <stack>

using namespace std;

long long N;
int K;
stack<char> s;

int main(int argc, char const *argv[])
{
    cin >> N;

    while (N && K++ <= 99)
    {
        if (N & 1)
        {
            N = N * 2;
            s.push('/');
        }
        else if (N & 2)
        {
            N = N - 2;
            s.push('+');
        }
        else
        {
            N = N / 2;
            s.push('*');
        }
    }

    if (K > 99)
        cout << -1 << "\n";
    else
    {
        cout << s.size() << "\n";
        while (!s.empty())
        {
            cout << "[" << s.top() << "]" << " ";
            s.pop();
        }
    }

    return 0;
}
