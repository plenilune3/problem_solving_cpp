#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> s;
    int answer = 0;

    int K;
    cin >> K;

    for (int i = 0; i < K; i++)
    {
        int m;
        cin >> m;
        answer += m;

        if (m == 0)
        {
            int t = s.top();
            answer -= t;
            s.pop();
        }
        else
            s.push(m);
    }

    cout << answer << "\n";

    return 0;
}
